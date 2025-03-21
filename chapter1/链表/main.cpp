#include <iostream>
#include <vector>
#include <math.h>
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
    std::cout << "头节点初始化成功" << std::endl;
}

void inserHead(Node *L, ElemType e)
{
    Node *p = new Node();
    p->data = e;
    p->next = L->next;
    L->next = p;
    std::cout << "在头部插入元素" << e << std::endl;
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
    std::cout << "在尾部插入元素" << e << std::endl;
}

void ListNode(Node *L)
{
    Node *p = L->next;
    std::cout << "列举出链表的所有元素" << std::endl;
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
    std::cout << "在" << "链表的" << pos << " 位置插入了 " << e << " 元素" << std::endl;
}
int List_get_length(Node *L)
{
    int count = 0;
    Node *p = L->next;
    while (p != NULL)
    {

        p = p->next;
        count++;
    }
    return count;
}

void Listlength(Node *L)
{
    int count = 0;
    Node *p = L->next;
    while (p != NULL)
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
    std::cout << "删除了" << "链表中" << "第 " << pos << " 个元素 " <<delete_pos_Node->data <<std::endl;
    pos_before_Node->next = delete_pos_Node->next;
    delete[] delete_pos_Node;

}

void find_from_last(Node *L, int pos)

{
    Node *fast = L->next; //  快慢指针指向除去头结点的第一个节点
    Node *slow = L->next;
    for (int i = 0; i < pos; i++) // 快指针先走 几步

    {

        fast = fast->next;
    }
    while (fast != NULL) // 循环当  fast 指向NULL的时候停止，fast 比slow快pos个身位

    {
        fast = fast->next;
        slow = slow->next;
    }
    std::cout << "链表中倒数第 " << pos << "个元素是：";
    std::cout << slow->data << std::endl;
}
void delete_repeated_ele(Node *L)
{

    int List_length = List_get_length(L);
    std::vector<bool> Dictionary_array(999);
    for (int i = 0; i < List_length; i++) //  给字典数组赋值0
    {
        Dictionary_array[i] = 0;
    }
    Node *prev_p = L;     
    Node *p = L->next;   //   P 指向第一个节点
    int pos = 1; //  读取LIST
    while (p != NULL)
    {
        if (Dictionary_array[p->data] == 0)  //  元素首次出现
        {
            Dictionary_array[p->data] = 1;
            prev_p = prev_p ->next  ; 
            p = p->next; 
            pos ++  ; 
        }
        else if (Dictionary_array[p->data] == 1)  //  元素已经出现过了
        {
            Listdelete(L, pos);
        }
        p = prev_p->next ;

 
    }
}

void find_max()
{
   
 
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
    Listlength(list);
    ListNode(list);
    Listdelete(list, 2);
    ListNode(list);
    Listlength(list);
    find_from_last(list, 3);
    insertail(list, 60);
    insertail(list, 70);
    ListNode(list);
    Listlength(list);
    find_from_last(list, 3);
    delete_repeated_ele(list);
    // ListNode(list);
    // ListNode(list);
    ListNode(list);
    delete  list;
}