#include "pch.h"
#include <algorithm>
#include "sort.h"

void Sort::bubbleSort(std::vector<int>& vec)
{
    if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}
