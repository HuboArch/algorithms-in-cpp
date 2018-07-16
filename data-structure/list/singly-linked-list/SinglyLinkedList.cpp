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

/**
 * 头部插入结点
 * @param pNode
 */
void SinglyLinkedList::insertHead(Node *pNode)
{
    Node *tmpCell = m_pList->next;

    auto *newNode = new Node;
    newNode->data = pNode->data;
    newNode->next = tmpCell;

    m_pList->next = newNode;

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
 * 在指定位置插入结点
 * @param i 要插入的位置 取值范围：[1, m_iLength + 1]
 * @param pNode 要被插入的结点
 */
bool SinglyLinkedList::insertNode(int i, Node *pNode)
{
    if (i < 1 || i > m_iLength + 1)
    {
        return false;
    }

    Node *p = m_pList;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }

    auto newNode = new Node;
    newNode->data = pNode->data;
    newNode->next = p->next;

    p->next = newNode;

    return true;
}

/**
 * 删除指定位置的结点
 * @param i 取值范围：[1, m_iLength]
 * @param pNode
 */
bool SinglyLinkedList::deleteNode(int i, Node *pNode)
{
    if (isEmpty() || i < 1 || i > m_iLength)
    {
        return false;
    }

    Node *prevNode = m_pList;
    Node *curNode = m_pList->next;
    for (int j = 1; j < i; j++)
    {
        prevNode = curNode;
        curNode = curNode->next;
    }

    prevNode->next = curNode->next;

    // 保存被删除结点的数据域的值
    pNode->data = curNode->data;
    delete curNode;
    curNode = nullptr;

    m_iLength--;

    return true;
}

/**
 * 获取第 i 个结点
 * @param i 取值范围：[1, m_iLength]
 * @param pNode
 * @return
 */
bool SinglyLinkedList::getNode(int i, Node *pNode)
{
    if (i < 1 || i > m_iLength)
    {
        return false;
    }

    Node *p = m_pList;
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

    for (int i = 1; p; i++)
    {
        if (p->data == pNode->data)
        {
            return i;
        }
        p = p->next;
    }

    return -1;
}

bool SinglyLinkedList::prevNode(Node *pCurNode, Node *pPrevNode)
{
    Node *p = m_pList->next;

    while (p->next != nullptr)
    {
        if (p->next->data == pCurNode->data)
        {
            pPrevNode = p;
            return true;
        }

        p = p->next;
    }

    return false;
}

bool SinglyLinkedList::nextNode(Node *pCurNode, Node *pNextNode)
{
    Node *p = m_pList->next;

    while (p != nullptr)
    {
        if (p->data == pCurNode->data)
        {
            pNextNode->data = p->next->data;

            return true;
        }

        p = p->next;
    }

    return false;
}

void SinglyLinkedList::traverseList()
{
    Node *p = m_pList->next;

    while (p != nullptr)
    {
        p->printNode();
        p = p->next;
    }
}
