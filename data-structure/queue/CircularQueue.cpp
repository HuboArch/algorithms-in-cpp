//
// Created by dean on 2018/8/8.
//

#include "header/CircularQueue.h"
#include <iostream>

using namespace std;

/**
 * ��ʼ�����ζ���
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
    m_iLength = 0;
}

/**
 * �ж϶����Ƿ�Ϊ��
 * @return bool
 */
bool CircularQueue::IsEmpty() const
{
    return m_iLength == 0;
}

/**
 * �ж϶����Ƿ�����
 * @return bool
 */
bool CircularQueue::IsFull() const
{
    return m_iLength == m_iCapacity;
}

/**
 * ��ȡ���г���
 * @return int
 */
int CircularQueue::GetLength() const
{
    return m_iLength;
}

/**
 * ��β���Ԫ��
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

    m_iLength++;

    return true;
}

/**
 * ��ͷ����Ԫ��
 * @param elem
 * @return
 */
bool CircularQueue::DeQueue(int& elem)
{
    if (IsEmpty())
    {
        return false;
    }

    elem = m_pQueue[m_iHead++];
    m_iHead %= m_iCapacity;

    m_iLength--;

    return true;
}

/**
 * ����ѭ������
 */
void CircularQueue::Traverse()
{
    for (int i = m_iHead; i < m_iHead + m_iLength; i++)
    {
        cout << m_pQueue[i % m_iCapacity] << endl;
    }
}
