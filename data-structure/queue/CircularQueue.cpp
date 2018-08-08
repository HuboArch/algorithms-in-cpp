//
// Created by dean on 2018/8/8.
//

#include "header/CircularQueue.h"

/**
 * 初始化环形队列
 * @param capacity
 */
CircularQueue::CircularQueue(int capacity)
{
    m_iCapacity = capacity;
    m_iHead = 0;
    m_iTail = 0;
    m_iLength = 0;
    m_pQueue = new int[capacity];
}

/**
 * 销毁环形队列
 */
CircularQueue::~CircularQueue()
{
    delete[] m_pQueue;
    m_pQueue = nullptr;
}

/**
 * 清空环形队列
 */
void CircularQueue::ClearQueue()
{
    m_iHead = 0;
    m_iTail = 0;
    m_iLength = 0;
}

/**
 * 判断队列是否为空
 * @return bool
 */
bool CircularQueue::IsEmpty() const
{
    return m_iLength == 0;
}

/**
 * 判断队列是否已满
 * @return bool
 */
bool CircularQueue::IsFull() const
{
    return m_iLength == m_iCapacity;
}

/**
 * 获取队列长度
 * @return int
 */
int CircularQueue::GetLength() const
{
    return m_iLength;
}

/**
 * 队尾添加元素
 * @param elem
 * @return bool
 */
bool CircularQueue::EnQueue(int elem)
{
    if (IsFull())
    {
        return false;
    }

    m_pQueue[m_iTail++] = elem;
    m_iTail %= m_iCapacity;

    m_iLength--;

    return true;
}
