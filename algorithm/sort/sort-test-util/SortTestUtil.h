//
// Created by dean on 2018/8/9.
//

#ifndef ALGORITHMS_IN_CPP_SORTUTIL_H
#define ALGORITHMS_IN_CPP_SORTUTIL_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

namespace SortTestUtil
{
    /**
     * 生成一个随机数组 元素的随机范围是：[rangeL, rangeR]
     * @param n
     * @param rangeL
     * @param rangeR
     * @return
     */
    int *generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);

        auto *arr = new int[n];
        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

        return arr;
    }

    /**
     * 打印数组的所有元素
     * @tparam T
     * @param arr
     * @param n
     */
    template<typename T>
    void printArray(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    /**
     * 判断数组是否有序
     * @tparam T 元素类型
     * @param arr
     * @param len 数组长度
     * @return bool
     */
    template<typename T>
    bool isSorted(T arr[], int len)
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSortPerformance(const string& sortName, void(*sort)(T[], int), T arr[], int len)
    {
        clock_t startTime = clock();
        sort();
        clock_t endTime = clock();

        assert(isSorted(arr, len));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
}

#endif //ALGORITHMS_IN_CPP_SORTUTIL_H
