//
// Created by dean on 2018/8/8.
//

#include "header/CircularQueue.h"

/**
 * 初始化环形队列
 *
 * @param capacity 
 */
CircularQueue::CircularQueue(int capacity)
{
    m_iCapacity = capacity;
    m_iHead = 0;
    m_iTail = 0;
    m_ilength = 0;
    m_pQueue = new int[capacity];
}
