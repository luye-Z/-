//  数据结构与算法第一题目
//  气泡算法
// 从小到大排序

#include <iostream>
void bubble_sort1(int a[], int length) //   数组长度n

{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < length - 1; i++)
        {

            if (a[i] > a[i + 1])
            {

                std::swap(a[i], a[i + 1]);
                sorted = false;
            }
        }

        length--;
    }
}

int main()
{

    const int length = 6;
    int a[length] = {99, 6, 5, 1, -999, 45};
    bubble_sort1(a, length);

    for (int i = 0; i < length; i++)
    {

        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}