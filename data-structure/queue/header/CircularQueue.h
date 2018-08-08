//
// Created by dean on 2018/8/8.
//

#ifndef ALGORITHMS_IN_CPP_CIRCULARQUEUE_H
#define ALGORITHMS_IN_CPP_CIRCULARQUEUE_H


class CircularQueue
{
public:
    explicit CircularQueue(int capacity); // 创建队列

    virtual ~CircularQueue();       // 销毁队列

    void ClearQueue();              // 清空队列

    bool IsEmpty() const;           // 判断是否为空

    bool IsFull() const;            // 判断是否已满

    int GetLength() const;          // 获取队列长度

    bool EnQueue(int elem);         // 队尾添加元素

    bool DeQueue(int& elem);        // 队头删除元素

    void Traverse();                // 遍历队列

private:
    int *m_pQueue;      // 队列数组指针
    int m_iLength;      // 队列长度
    int m_iCapacity;    // 队列容量
    int m_iHead;        // 队头
    int m_iTail;        // 队尾
};


#endif //ALGORITHMS_IN_CPP_CIRCULARQUEUE_H
