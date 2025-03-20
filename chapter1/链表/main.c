#include <stdio.h>
#include <stdlib.h>

// 使用 typedef 定义类型别名
typedef int ElemType;

// 定义链表节点结构
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

// 初始化链表
Node *initList()
{
    // 使用 malloc 分配内存
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

// 在链表头部插入元素
void inserHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    p->data = e;
    p->next = L->next;
    L->next = p;
}

// 打印链表元素
void ListNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *list = initList();
    if (list == NULL)
    {
        return 1;
    }
    inserHead(list, 10);
    inserHead(list, 20);
    inserHead(list, 30);
    ListNode(list);

    // 释放链表内存，避免内存泄漏
    Node *current = list;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}