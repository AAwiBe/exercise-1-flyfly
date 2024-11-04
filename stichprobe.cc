#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
    std::ifstream file("datensumme.txt");
    if (!file) {
        std::cerr << "Error: Could not open file 'datensumme.txt'.\n";
        return 1;
    }

    std::vector<double> numbers;
    double number;
    int N = 0;

    // Read numbers from file and store them in a vector
    while (file >> number) {
        numbers.push_back(number);
        N++;
    }
    file.close();

    // Calculate the mean
    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    double mean = sum / N;
    std::cout << "Mean (ā): " << mean << std::endl;

    // Calculate the variance
    double variance_sum = 0.0;
    for (double num : numbers) {
        variance_sum += (num - mean) * (num - mean);
    }
    double variance = variance_sum / N;
    std::cout << "Variance (V): " << variance << std::endl;

    // Calculate the standard deviation
    double standard_deviation = std::sqrt(variance);
    std::cout << "Standard Deviation (σ): " << standard_deviation << std::endl;

    return 0;
}