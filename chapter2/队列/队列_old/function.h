#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#define MAXSIZE 100

using ElemType = int;

struct Queue
{
    ElemType *data = new ElemType[MAXSIZE];
    int front;
    int rear;
};
Queue *initQueue();
bool isEmpty(Queue *Q);
ElemType dequeue(Queue *Q);
int queueFull(Queue *Q); // ÂúÁË  1   £¬Ã»Âú  0
void equeue(Queue *Q, ElemType e);
ElemType get_Head_data(Queue *Q);
void free_Queue(Queue *Q);
#endif