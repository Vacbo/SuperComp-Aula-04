#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error reading file" << std::endl;
        return 1;
    }

    std::string line;
    int totalLines = 0;
    int totalWords = 0;
    std::map<std::string, int> wordFrequency;

    while (std::getline(inputFile, line)) {
        totalLines++;

        std::istringstream lineStream(line);
        std::string word;

        while (lineStream >> word) {
            word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            totalWords++;
            wordFrequency[word]++;
        }
    }
    inputFile.close();

    std::string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto &pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    double averageWordsPerLine = (totalLines > 0) ? static_cast<double>(totalWords) / totalLines : 0.0;

    outputFile << "Total Words: " << totalWords << std::endl;
    outputFile << "Total Lines: " << totalLines << std::endl;
    outputFile << "Average number of words: " << averageWordsPerLine << std::endl;
    outputFile << "Most frequent word: " << mostFrequentWord << " (freq: " << maxFrequency << ")" << std::endl;

    outputFile.close();

    std::cout << "Stats saved in 'output.txt'." << std::endl;

    return 0;
}
