//
// Created by dean on 2018/7/12.
//

#include <cstdio>
#include "header/SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
    m_pList = new Node;

    m_pList->data = 0;
    m_pList->next = nullptr;

    m_iLength = 0;
}

/**
 * 销毁链表
 */
SinglyLinkedList::~SinglyLinkedList()
{
    clearList();

    delete m_pList;
    m_pList = nullptr;
}

/**
 * 清空链表
 */
void SinglyLinkedList::clearList()
{
    Node *p = m_pList->next;

    while (p != nullptr)
    {
        Node *tmpCell = p->next;
        delete p;
        p = tmpCell;
    }
    m_pList->next = nullptr;
}

bool SinglyLinkedList::isEmpty()
{
    return m_iLength == 0;
}

int SinglyLinkedList::getLength()
{
    return m_iLength;
}
