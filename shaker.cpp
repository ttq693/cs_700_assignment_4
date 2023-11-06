/// \brief Author         : Tanzila Nasrin Tazin
/// \brief Creation Date  : 2023-11-04
/// \brief filename       : shaker.cpp

#include "shaker.h"

void ShakerSort::sortAscending(std::vector<int> &arr) {
    bool swapped;
    int n = arr.size();
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

void ShakerSort::sortDescending(std::vector<int> &arr) {
    bool swapped;
    int n = arr.size();
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (arr[i] > arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}
