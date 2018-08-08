//
// Created by dean on 2018/8/8.
//

#include "header/CircularQueue.h"

/**
 * ��ʼ�����ζ���
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

/**
 * ���ٻ��ζ���
 */
CircularQueue::~CircularQueue()
{
    delete[] m_pQueue;
    m_pQueue = nullptr;
}

/**
 * ��ջ��ζ���
 */
void CircularQueue::ClearQueue()
{
    m_iHead = 0;
    m_iTail = 0;
    m_ilength = 0;
}

/**
 * �ж϶����Ƿ�Ϊ��
 *
 * @return bool
 */
bool CircularQueue::IsEmpty() const
{
    return m_ilength == 0;
}
