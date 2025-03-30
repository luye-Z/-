#include <iostream>

using ElemType = int;

struct Node
{

    ElemType data;
    Node *next;
};

Node *creat_new_Node() //  创建首节点
{
    Node *Head = new Node();
    Head->data = 0;
    Head->next = NULL;
    return Head;
}

ElemType GetElem(Node *L, int pos)

{
    int count = 0;
    Node *temp_Node = L;
    while ((temp_Node->next != NULL) && (count < pos))
    {
        temp_Node = temp_Node->next;
        count++;
    }
    if (count < pos)

    {
        std::cout << "访问错误, 无法得到位置为 " << pos << "的节点数据" << std::endl;
        return -1;
    }
    else

    {

        return temp_Node->data;
    }
}

     



int main()
{
    Node *my_list = creat_new_Node(); // 初始化

    return 0;
}