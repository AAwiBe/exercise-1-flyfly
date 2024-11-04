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

    std::ofstream meanFile("mittelwerte.txt");
    std::ofstream varianceFile("varianzen.txt");

    if (!meanFile || !varianceFile) {
        std::cerr << "Error: Could not create output files.\n";
    }

    double overall_mean_sum = 0.0;
    double overall_variance_sum = 0.0;
    int groupe_size = 9;
    int num_groups = N / groupe_size;

    for (int i=0; i<num_groups; i++) {
        double group_sum = 0.0;
        double group_variance_sum = 0.0;

        for (int j=0; j<groupe_size;j++){
            group_sum += numbers[i*groupe_size + j];
        }
        double group_mean = group_sum / groupe_size;
        overall_mean_sum += group_mean;
        meanFile << group_mean << std::endl;

        for (int j=0; j<groupe_size;j++){
            group_variance_sum += (numbers[i*groupe_size + j] - group_mean) *(numbers[i*groupe_size + j] - group_mean);
        }
        double group_variance = group_variance_sum / groupe_size;
        overall_variance_sum += group_variance;
        varianceFile << group_variance << std::endl;
    }

    meanFile.close();
    varianceFile.close();

    double mean_of_means = overall_mean_sum / num_groups;
    double mean_of_variances = overall_variance_sum / num_groups;

    std::cout << "Mean of means: " << mean_of_means << std::endl;
    std::cout << "Mean of variances: " << mean_of_variances << std::endl;

    return 0;
}