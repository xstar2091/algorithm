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

TEST(Sort, TestName) {
    for (size_t i = 0; i < unsorted_list.size(); i++) {
        auto actual = unsorted_list[i];
        const auto& expected = expected_list[i];
        Sort::bubbleSort(actual);
        EXPECT_EQ(actual, expected);
    }
}