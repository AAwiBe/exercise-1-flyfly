#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("daten.txt");
    std::ofstream outputFile("datensumme.txt");

    if (!inputFile) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    if (!outputFile) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    int num1, num2;
    for (int i = 0; i < 234; ++i) {
        inputFile >> num1 >> num2;
        if (inputFile) {
            int sum = num1 + num2;
            outputFile << sum << std::endl;
        } else {
            std::cerr << "Error reading pair " << i + 1 << std::endl;
            break;
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}