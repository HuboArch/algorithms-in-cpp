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

    void clearList();

    bool isEmpty();

    int getLength();

    void insertHead(Node *pNode);

    void insertTail(Node *pNode);

    bool insertNode(int i, Node *pNode);

    bool deleteNode(int i, Node *pNode);

    bool getNode(int i, Node *pNode);

    int locateNode(Node *pNode);

    bool prevNode(Node *pCurNode, Node *pPrevNode);

    bool nextNode(Node *pCurNode, Node *pNextNode);

    void traverseList();

private:
    Node *m_pList;
    int m_iLength;
};


#endif //ALGORITHMS_IN_CPP_SINGLYLINKEDLIST_H
