//
// Created by dean on 2018/7/12.
//

#include <iostream>
#include <cstdio>
#include "header/SinglyLinkedList.h"

using namespace std;

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

/**
 * 头部插入结点
 * @param pNode
 */
void SinglyLinkedList::insertHead(Node *pNode)
{
    Node *tmpCell = m_pList->next;

    auto *newNode = new Node;
    newNode->data = pNode->data;

    m_pList->next = newNode;
    newNode->next = tmpCell;

    m_iLength++;
}

/**
 * 尾部插入结点
 * @param pNode
 */
void SinglyLinkedList::insertTail(Node *pNode)
{
    Node *p = m_pList;
    while (p->next != nullptr)
    {
        p = p->next;
    }

    auto *newNode = new Node;
    newNode->data = pNode->data;
    newNode->next = nullptr;

    p->next = newNode;

    m_iLength++;
}

/**
 * 在指定的索引位置后面插入结点
 * @param i 要插入的位置索引 [0, m_iLength - 1]
 * @param pNode 要被插入的结点
 */
bool SinglyLinkedList::insertNode(int i, Node *pNode)
{
    if (i < 0 || i >= m_iLength)
    {
        return false;
    }

    Node *p = m_pList;
    for (int j = 0; j <= i; j++)
    {
        p = p->next;
    }

    auto *newNode = new Node;
    newNode->data = pNode->data;
    newNode->next = p->next;

    p->next = newNode;

    return true;
}

/**
 * 删除指定位置的结点
 * @param i 取值范围：[0, m_iLength - 1]
 * @param pNode
 */
bool SinglyLinkedList::deleteNode(int i, Node *pNode)
{
    if (i < 0 || i >= m_iLength)
    {
        return false;
    }

    Node *prevNode = m_pList;
    Node *curNode = m_pList->next;
    for (int j = 0; j < i; j++)
    {
        prevNode = curNode;
        curNode = curNode->next;
    }

    prevNode->next = curNode->next;

    // 保存被删除结点的数据域的值
    pNode->data = curNode->data;
    delete curNode;

    m_iLength--;

    return true;
}

/**
 * 获取指定索引位置的结点数据域的值
 * @param i 取值范围：[0, m_iLength - 1]
 * @param pNode
 * @return
 */
bool SinglyLinkedList::getNode(int i, Node *pNode)
{
    if (i < 0 || i > m_iLength - 1)
    {
        return false;
    }

    Node *p = m_pList->next;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
    }

    pNode->data = p->data;

    return true;
}

/**
 * 获取指定结点的位置索引
 * @param pNode 待匹配的结点
 * @return 查找失败返回 -1
 */
int SinglyLinkedList::locateNode(Node *pNode)
{
    Node *p = m_pList->next;
    int index = 1;

    while (p != nullptr)
    {
        if (p->data == pNode->data)
        {
            return index;
        }

        p = p->next;
        index++;
    }

    return -1;
}

/**
 * 查找上一个结点元素
 * @param pNode 要查找的结点的数据域的值
 * @param pPrevNode
 * @return
 */
bool SinglyLinkedList::prevNode(Node *pNode, Node *pPrevNode)
{
    Node *p = m_pList->next;

    if (p == pNode)
    {
        return false;
    }

    while (p->next != nullptr)
    {
        if (p->next->data == pNode->data)
        {
            pPrevNode = p;
            return true;
        }

        p = p->next;
    }
    return false;
}

/**
 * 查找下一个结点元素
 * @param pNode 传递要查找结点的数据域的值
 * @param pNextNode
 * @return
 */
bool SinglyLinkedList::nextNode(Node *pNode, Node *pNextNode)
{
    Node *p = m_pList->next;

    while (p != nullptr)
    {
        if (p->data == pNode->data)
        {
            pNextNode->data = p->next->data;
            return true;
        }

        p = p->next;
    }

    return false;
}

/**
 * 遍历链表
 */
void SinglyLinkedList::traverseList()
{
    Node *p = m_pList->next;

    while (p != nullptr)
    {
        p->printNode();
        p = p->next;
    }
}

/**
 * 测试链表
 * @param pList
 */
void SinglyLinkedList::test(SinglyLinkedList *pList)
{
    // 链表首部依次插入三个结点
    Node n1{};
    Node n2{};
    Node n3{};

    n1.data = 1;
    n2.data = 2;
    n3.data = 3;

    pList->insertHead(&n1);
    pList->insertHead(&n2);
    pList->insertHead(&n3);

//    pList->traverseList();

    // 链表尾部插入结点
    Node n4{};
    Node n5{};
    Node n6{};
    n4.data = 4;
    n5.data = 5;
    n6.data = 6;

    pList->insertTail(&n4);
    pList->insertTail(&n5);
    pList->insertTail(&n6);

//    pList->traverseList();

    // 链表中间位置插入结点
    Node n7{};
    n7.data = 7;

    pList->insertNode(3, &n7);

//    pList->traverseList();

    // 删除指定位置的结点
    Node tmpCell{};

    pList->deleteNode(3, &tmpCell);

    cout << "data field of the deleted node is: " << tmpCell.data << endl;

//    pList->traverseList();

    // 获取指定位置的结点
    pList->getNode(2, &tmpCell);

    cout << "tmpCell.data = " << tmpCell.data;

    delete pList;
    pList = nullptr;
}
