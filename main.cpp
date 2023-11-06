/// \brief Author         : Tanzila Nasrin Tazin
/// \brief Creation Date  : 2023-11-04
/// \brief filename       : main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Shaker.h"
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    // Generate random numbers and store in a vector
    vector<int> numbers;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        // Generating random numbers between 0 and 999
        numbers.push_back(rand() % 1000);
    }

    // for Saving the vector in a file
    ofstream outputFile("input.txt");
    if (outputFile.is_open()) {
        for (int num : numbers) {
            outputFile << num << " ";
        }
        //vector saved in input.txt file
        outputFile.close();
        cout << "Vector saved in 'input.txt' file.\n";
    } else {
        cerr << "File error";
        return 1;
    }

    // Sort the saved vector in ascending order and save the execution time
    ShakerSort shakerSort;
    vector<int> ascending_Num(numbers); // Copy of original vector for sorting in ascending order
    auto startAscending = std::chrono::steady_clock::now();
    shakerSort.sortAscending(ascending_Num);
    auto endAscending = std::chrono::steady_clock::now();

    cout << "Time taken for sorting in ascending order: "
              << std::chrono::duration_cast<std::chrono::microseconds>(endAscending - startAscending).count()
              << " microseconds." << std::endl;

    // Save sorted ascending order to a file
    ofstream asc_File("C://Users//tazin//CLionProjects//Assignment_4//Ascending_sort.txt");
    if (asc_File.is_open()) {
        for (int num : ascending_Num) {
            asc_File << num << " ";
        }
        asc_File.close();
        cout << "Sorted vector in ascending order saved in 'Ascending_sort.txt' file.\n";
    } else {
        std::cerr << "File error";
        return 1;
    }

    // Sort the vector in descending order and report execution time
    vector<int> descending_Num(numbers); // Copy of original vector for sorting in descending order

    auto startDescending = std::chrono::steady_clock::now();
    shakerSort.sortDescending(descending_Num);
    auto endDescending = std::chrono::steady_clock::now();

    cout << "Time taken for sorting in descending order: "
              << std::chrono::duration_cast<std::chrono::microseconds>(endDescending - startDescending).count()
              << " microseconds." << std::endl;

    // Save sorted descending order to a file
    ofstream desc_File("C://Users//tazin//CLionProjects//Assignment_4//Descending_sort.txt");
    if (desc_File.is_open()) {
        for (int num : descending_Num) {
            desc_File << num << " ";
        }
        desc_File.close();
        cout << "Sorted vector in descending order saved in 'Descending_sort.txt' file.\n";
    } else {
        cerr << "File error";
        return 1;
    }

    return 0;
}
