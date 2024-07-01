#pragma once

#include <vector>

class Sort
{
public:
    static void bubbleSort(std::vector<int>& vec);
    static void selectionSort(std::vector<int>& vec);
    static void insertionSort(std::vector<int>& vec);
    static void quickSort(std::vector<int>& vec, int left, int right);
};

