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

SinglyLinkedList::~SinglyLinkedList()
{

}

bool SinglyLinkedList::isEmpty()
{
    return m_iLength == 0;
}

int SinglyLinkedList::getLength()
{
    return m_iLength;
}
