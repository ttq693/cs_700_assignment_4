/// \brief Author         : Tanzila Nasrin Tazin
/// \brief Creation Date  : 2023-11-04

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Shaker.h"

int main() {
    int size;
    std::cout << "Enter the size of the vector: ";
    std::cin >> size;

    // Generate random numbers and store in a vector
    std::vector<int> numbers;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        numbers.push_back(rand() % 100);  // Generating random numbers between 0 and 99
    }

    // Save the generated vector in a file
    std::ofstream outputFile("input.txt");
    if (outputFile.is_open()) {
        for (int num : numbers) {
            outputFile << num << " ";
        }
        outputFile.close();
        std::cout << "Vector saved in 'input.txt' file.\n";
    } else {
        std::cerr << "Unable to open the file.";
        return 1;
    }

    // Display the generated vector
    std::cout << "Generated vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the vector in ascending order
    ShakerSort shakerSort;
    shakerSort.sortAscending(numbers);

    std::cout << "Sorted vector in ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the vector in descending order
    shakerSort.sortDescending(numbers);

    std::cout << "Sorted vector in descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}