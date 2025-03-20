#include <iostream>
#define  MAXSIZE  100 

typedef   int ElemType ; 

typedef struct
{
    ElemType data[MAXSIZE];
    int length ; 



}SeqList ; 

void initList(SeqList *L)

{
    L-> length = 0 ;

}


int main()
{

    SeqList  list ;
    initList(&list);
    std::cout<<"初始化成功，目前长度占用:  "<<list.length<<std::endl;
    std::cout<<"目前占用内存： "<<sizeof(list.data)<<std::endl;

    return 0 ;

}