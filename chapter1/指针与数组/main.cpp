#include <iostream>

int main()
{

    int array1[] = {1, 2, 3, 4, 5};
    int *p = array1;
    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
    {
        std::cout << *(p + i) << " ";

    }
    std::cout << std::endl;

    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
    {
        std::cout << *(p + i) << " ";
        
    }
    std::cout << std::endl;
}