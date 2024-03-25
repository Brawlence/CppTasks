#include <iostream>
#include <fstream>
#include <string>
#include <regex>


int main() {
    std::ifstream inputFile("19.03.24_2_in.csv");
    std::ofstream outputFile("19.03.24_2_mod.csv");

    if (!(inputFile.is_open()&&outputFile.is_open())) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    std::string line;
    int lineCounter = 0;

    std::getline(inputFile, line);
    outputFile << line << std::endl; // pass the HEADER

    std::regex detection_regex("<_____>");
    std::string replacement = "Piket";
    bool PRIMED = false;

    while (std::getline(inputFile, line)) {
        if (line.find(replacement) != std::string::npos) PRIMED = true;
        if (lineCounter % 10 == 0) {
            if (PRIMED) {
                line = std::regex_replace(line, detection_regex, replacement); // <_____> → Piket
                PRIMED = false;
            };
            outputFile << line << std::endl;
        }
        lineCounter++;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}