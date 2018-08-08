//
// Created by dean on 2018/8/8.
//

#ifndef ALGORITHMS_IN_CPP_CIRCULARQUEUE_H
#define ALGORITHMS_IN_CPP_CIRCULARQUEUE_H


class CircularQueue
{
public:
    CircularQueue(int m_iCapacity); // ��������

    virtual ~CircularQueue();       // ���ٶ���

    void ClearQueue();              // ��ն���

    bool IsEmpty() const;           // �ж��Ƿ�Ϊ��

    int GetLength() const;          // ��ȡ���г���

    bool EnQueue(int elem);         // ��β����Ԫ��

    bool DeQueue(int& elem);        // ��ͷɾ��Ԫ��

    void Traverse();                // ��������

private:
    int *m_pQueue;      // ��������ָ��
    int m_ilength;      // ���г���
    int m_iCapacity;    // ��������
    int m_iHead;        // ��ͷ
    int m_iTail;        // ��β
};


#endif //ALGORITHMS_IN_CPP_CIRCULARQUEUE_H