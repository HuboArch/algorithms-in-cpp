//
// Created by dean on 2018/8/13.
//

#ifndef ALGORITHMS_IN_CPP_SELECTIONSORT_H
#define ALGORITHMS_IN_CPP_SELECTIONSORT_H

#include <algorithm>

using namespace std;

/**
 * ѡ������
 * @tparam T ����Ԫ������
 * @param arr ����
 * @param len ���鳤��
 */
template<typename T>
void selectionSort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

#endif //ALGORITHMS_IN_CPP_SELECTIONSORT_H
