//
// Created by dean on 2018/7/12.
//

#ifndef ALGORITHMS_IN_CPP_SINGLYLINKEDLIST_H
#define ALGORITHMS_IN_CPP_SINGLYLINKEDLIST_H

#include "Node.h"

class SinglyLinkedList
{
public:
    SinglyLinkedList();

    ~SinglyLinkedList();

    bool isEmpty();

    int getLength();

private:
    Node *m_pList;
    int m_iLength;
};


#endif //ALGORITHMS_IN_CPP_SINGLYLINKEDLIST_H
