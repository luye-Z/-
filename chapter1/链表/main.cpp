#include <iostream>

using ElemType = int;

struct Node
{
    ElemType data;
    struct Node *next;
};

Node *initList()
{

    Node *head = new Node();
    head->data = 0;
    head->next = NULL;
    return head;
}

void inserHead(Node *L, ElemType e)
{
    Node *p = new Node();
    p->data = e;
    p->next = L->next;
    L->next = p;
}

void insertail(Node *L, ElemType e)
{
    if (L == nullptr)
    {
        return;
    }
    Node *p = L;
    while ((p->next) != NULL)
    {
        p = p->next;
    }
    Node *tail = p;
    Node *q = new Node();

    q->next = NULL;
    q->data = e;
    tail->next = q;
}

void ListNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {

        std::cout << p->data << "  ";
        p = p->next;
    }
    std::cout << std::endl;
}

void Listinsert(Node *L, int pos, ElemType e)

{

    Node *p = L;

    for (int i = 0; i < pos - 1; i++)
    {
        if (p == NULL)
        {
            return;
        }

        p = p->next;
    }
    Node *pos_before_Node = p; // 获取插入位置的前一个节点(前驱结点)
    Node *q = new Node();
    q->next = pos_before_Node->next;
    q->data = e;
    pos_before_Node->next = q;
}

void Listlength(Node *L)
{
    int count = 0;
    Node *p = L;
    while (p->next != NULL)
    {

        p = p->next;
        count++;
    }
    std::cout << "链表的长度是： " << count << std::endl;
}

void Listdelete(Node *L, int pos)
{
    Node *p = L;
    for (int i = 0; i < pos - 1; i++)
    {

        if (p == NULL)
        {

            return;
        }

        p = p->next;
    }
    Node *pos_before_Node = p; // 获取删除位置的前一个节点(前驱结点)
    Node *delete_pos_Node = p->next;
    pos_before_Node->next = delete_pos_Node->next;
    delete[] delete_pos_Node;
}

int main()
{
    Node *list = initList();
    inserHead(list, 10);
    inserHead(list, 20);
    inserHead(list, 30);
    insertail(list, 10);
    insertail(list, 20);
    insertail(list, 30);
    insertail(list, 40);
    insertail(list, 50);
    Listinsert(list, 2, 999);
    ListNode(list);
    Listdelete(list, 2);
    ListNode(list);
    Listlength(list);
    delete[] list;
}