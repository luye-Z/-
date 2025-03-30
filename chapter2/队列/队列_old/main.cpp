/*
2025 年3月24日
晚上   周禄也
*/

#include <iostream>
#include "function.h"

int main()
{
    Queue *my_queue = new Queue();
    my_queue = initQueue();
    equeue(my_queue, 66);
    equeue(my_queue, 77);
    equeue(my_queue, 88);
    dequeue(my_queue);
    dequeue(my_queue);
    queueFull(my_queue);
    free_Queue(my_queue);
    return 0;
}