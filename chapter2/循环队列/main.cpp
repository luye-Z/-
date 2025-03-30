#include <iostream>

#define MAXSIZE 6

using ElemType = int;

struct Queue
{
    ElemType *data = new ElemType[MAXSIZE];
    int front;
    int rear;
};

Queue *initQueue()
{
    Queue *Q = new Queue();
    Q->front = 0;
    Q->rear = 0;
    return Q;
}
void equeue(Queue *Q, ElemType e)
{
    if ((Q->rear+1) % MAXSIZE == Q->front)
    {

        std::cout << "满了" << std::endl;
        return;
    }

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    std::cout << "数据入队成功,入队数据是： " << e << "  ";
    std::cout << "此时头指针指向位置：" << Q->front << "  ";
    std::cout << "此时尾指针指向位置：" << Q->rear << std::endl;

    return;
}

int main()

{
    Queue* my_queue = new Queue () ;
    my_queue = initQueue() ; 
    equeue(my_queue , 66);
    equeue(my_queue , 77);
    equeue(my_queue , 88);
    equeue(my_queue , 66);
    equeue(my_queue , 77);
    equeue(my_queue , 88);


    return 0;
}