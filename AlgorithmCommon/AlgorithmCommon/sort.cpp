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
        // ��ԭʼ�����з֡������򡱺͡�δ����������
        // ������[0, i)
        // δ����[i, n)
        // vec[i]����ѡ��ģ���ǰ��Ҫ�����Ԫ��
        int key = vec[i];
        // �ӡ������򡱵��������ʼ
        int j = i - 1;
        // ������������ȡ�ѡ������С��������������������ƶ�һ��λ��
        for (; j >= 0 && vec[j] > key; j--) {
            vec[j + 1] = vec[j];
        }
        // �ҵ�����λ�ã������ȥ
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
