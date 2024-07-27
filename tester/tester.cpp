#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

namespace fs = std::filesystem;

struct TestCaseResult {
    std::string case_name;
    bool success;
    double runtime;
};

std::string readFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    file << content;
}

std::vector<std::string> listFiles(const std::string& directory) {
    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(directory)) {
        files.push_back(entry.path().string());
    }
    return files;
}

bool compareFiles(const std::string& path1, const std::string& path2) {
    std::ifstream file1(path1);
    std::ifstream file2(path2);
    std::string line1, line2;
    while (std::getline(file1, line1)) {
        if (!std::getline(file2, line2) || line1 != line2) {
            return false;
        }
    }
    return !std::getline(file2, line2);
}

TestCaseResult runTestCase(const std::string& execPath, const std::string& inputPath, const std::string& outputPath) {
    std::string command = execPath + " < " + inputPath + " > temp.out";
    auto start = std::chrono::high_resolution_clock::now();
    system(command.c_str());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    bool success = compareFiles("temp.out", outputPath);
    fs::remove("temp.out");

    return TestCaseResult{
        fs::path(inputPath).stem().string(),
        success,
        diff.count()
    };
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <executable> <input_folder> <output_folder>\n";
        return 1;
    }

    std::string execPath = argv[1];
    std::string inputFolder = argv[2];
    std::string outputFolder = argv[3];

    std::vector<std::string> inputFiles = listFiles(inputFolder);
    int totalCases = inputFiles.size();
    int correctCases = 0;

    std::vector<TestCaseResult> results;

    for (const std::string& inputFile : inputFiles) {
        std::string caseName = fs::path(inputFile).stem().string();
        std::string outputFile = outputFolder + "/" + caseName + ".out";

        TestCaseResult result = runTestCase(execPath, inputFile, outputFile);
        results.push_back(result);
        if (result.success) {
            ++correctCases;
        }
    }

    for (const auto& result : results) {
        std::cout << "Case " << result.case_name << " ..................... " 
                  << (result.success ? "ok" : "wrong") 
                  << " (run time: " << result.runtime << "s)\n";
    }

    std::cout << "Total correct: " << correctCases << "/" << totalCases 
              << " (" << (100.0 * correctCases / totalCases) << "%)\n";

    return 0;
}