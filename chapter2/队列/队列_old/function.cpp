#include <iostream>
#include "function.h"

Queue *initQueue()
{
    Queue *Q = new Queue();
    Q->front = 0;
    Q->rear = 0;
    return Q;
}
bool isEmpty(Queue *Q) //  如果队列为空 返回  true
{
    if (Q->front == Q->rear)
    {
        std::cout << "队列是空的 ! " << std::endl;
        return true;
    }

    else
        std::cout << "队列不为空  " << std::endl;
    return false;
}

ElemType dequeue(Queue *Q)
{

    if (Q->front == Q->rear)
    {
        std::cout << "队列是空的 ! " << std::endl;
        return -1;
    }
    ElemType target_elem = Q->data[Q->front];
    Q->front++;

    std::cout << "数据出队成功,出队数据是： " << target_elem << "  ";
    std::cout << "此时头指针指向位置：" << Q->front << "  ";
    std::cout << "此时尾指针指向位置：" << Q->rear << std::endl;
    return target_elem;
}

int queueFull(Queue *Q) // 满了  1   ，没满  0
{
    if (Q->front > 0) //  队列头部有空余
    {
        int blank_length = Q->front; // blank_length  代表着头部空闲的长度  队列的头指针指向的位置  ，初始位置
        for (int i = Q->front; i <= Q->rear; ++i)
        {
            Q->data[i - blank_length] = Q->data[i]; //  队列数据现在出现了头部空闲  ，把左边的数据导到右边
        }
        Q->front = 0;
        Q->rear = Q->rear - blank_length;
        return 0;
    }

    else
        std::cout << "队列确实满了";

    return 1;
}

void equeue(Queue *Q, ElemType e)
{
    if (Q->rear >= MAXSIZE - 1) //  队尾指针到最头了么(满了吗?)
    {
        if (queueFull(Q))
        {
            std::cout << "队列已经满了,插值失败。" << std::endl;
            return;
        }
    }

    Q->data[Q->rear] = e; // 正常插值
    Q->rear++;            //  队尾指针++
    std::cout << "数据入队成功,入队数据是： " << e << "  ";
    std::cout << "此时头指针指向位置：" << Q->front << "  ";
    std::cout << "此时尾指针指向位置：" << Q->rear << std::endl;
    return;
}

ElemType get_Head_data(Queue *Q)
{
    if (isEmpty(Q)) // 为空
    {
        std::cout << "ERROR!" << std::endl;
        return -1;
    }

    else
    {

        return Q->data[Q->front];
    }
}

void free_Queue(Queue *Q)

{
    delete[] (Q->data);
    delete Q;
}