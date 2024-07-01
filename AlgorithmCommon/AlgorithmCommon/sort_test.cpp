#include "pch.h"
#include "sort.h"
#include <vector>

namespace {

    std::vector<std::vector<int>> unsorted_list = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {9, 8, 7, 6, 5, 4, 3, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 9},
        {9, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 3, 4, 9, 8, 7, 6, 5},
        {4, 3, 2, 1, 5, 6, 7, 8, 9},
        {9, 3, 5, 2, 1, 4, 8, 6, 7},
    };
    std::vector<std::vector<int>> expected_list = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 1, 1, 1, 1, 1, 1, 1, 9},
        {1, 1, 1, 1, 1, 1, 1, 1, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
    };
}

TEST(Sort, bubbleSort) {
    for (size_t i = 0; i < unsorted_list.size(); i++) {
        auto actual = unsorted_list[i];
        const auto& expected = expected_list[i];
        Sort::bubbleSort(actual);
        EXPECT_EQ(actual, expected);
    }
}

TEST(Sort, selectionSort) {
    for (size_t i = 0; i < unsorted_list.size(); i++) {
        auto actual = unsorted_list[i];
        const auto& expected = expected_list[i];
        Sort::selectionSort(actual);
        EXPECT_EQ(actual, expected);
    }
}

TEST(Sort, insertionSort) {
    for (size_t i = 0; i < unsorted_list.size(); i++) {
        auto actual = unsorted_list[i];
        const auto& expected = expected_list[i];
        Sort::insertionSort(actual);
        EXPECT_EQ(actual, expected);
    }
}

TEST(Sort, quickSort) {
    for (size_t i = 0; i < unsorted_list.size(); i++) {
        auto actual = unsorted_list[i];
        const auto& expected = expected_list[i];
        Sort::quickSort(actual, 0, static_cast<int>(actual.size()) - 1);
        EXPECT_EQ(actual, expected);
    }
}