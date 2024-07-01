#include "pch.h"
#include <algorithm>
#include "sort.h"

void Sort::bubbleSort(std::vector<int>& vec)
{
    /*if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }*/
    for (size_t i = 1; i < vec.size(); i++) {
        for (size_t j = 1; j < vec.size() - i + 1; j++) {
            if (vec[j - 1] > vec[j]) {
                std::swap(vec[j - 1], vec[j]);
            }
        }
    }
}

void Sort::selectionSort(std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}

void Sort::insertionSort(std::vector<int>& vec)
{
    int n = static_cast<int>(vec.size());
    for (int i = 1; i < n; i++) {
        // 对原始数列切分“已排序”和“未排序”两部分
        // 已排序：[0, i)
        // 未排序：[i, n)
        // vec[i]就是选择的，当前需要排序的元素
        int key = vec[i];
        // 从“已排序”的最大数开始
        int j = i - 1;
        // 若“最大数”比“选择数”小，则“最大数”依次向右移动一个位置
        for (; j >= 0 && vec[j] > key; j--) {
            vec[j + 1] = vec[j];
        }
        // 找到最终位置，插入进去
        vec[j + 1] = key;
    }
}

void Sort::quickSort(std::vector<int>& vec, int left, int right)
{
    if (left < right) {
        int i = left;
        int j = right;
        int x = vec[left];
        while (i < j) {
            for (; i < j && vec[j] > x; j--);
            if (i < j) {
                vec[i++] = vec[j];
            }
            for (; i < j && vec[i] < x; i++);
            if (i < j) {
                vec[j--] = vec[i];
            }
        }
        vec[i] = x;
        Sort::quickSort(vec, left, i - 1);
        Sort::quickSort(vec, i + 1, right);
    }
}
