#include <iostream>

// void swap_zly(int &num1, int &num2)
// {
//     int temp = 0;
//     temp = num1;
//     num1 = num2;
//     num2 = temp;
// }


void swap_zly(int *num1 , int *num2)
{


    int temp = 0;
    temp =*num1;
    *num1=*num2;
    *num2=temp;
}

int main()
{
    std::cout << "Please input twp numbers:  " << std::endl;
    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << "befor swap_zly: " << num1 << " " << num2 << std::endl;
    // swap_zly(num1, num2);
    swap_zly(&num1,&num2);
    std::cout << "after swap_zly: " << num1 << " " << num2 << std::endl;
}