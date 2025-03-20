#include <iostream>

using namespace std;

// 顺序表类
class SeqList
{
private:
    int *data;    // 存储数据的数组
    int size;     // 当前元素个数
    int capacity; // 顺序表的容量

    // 扩容函数
    void expand()
    {
        int newCapacity = capacity * 2;
        int *newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // 构造函数
    SeqList(int cap = 10) : size(0), capacity(cap)
    {
        data = new int[capacity];
    }

    // 析构函数
    ~SeqList()
    {
        delete[] data;
    }

    // 插入元素（尾插法）
    void push_back(int value)
    {
        if (size == capacity)
        {
            expand();
        }
        data[size++] = value;
    }

    // 在指定位置插入元素
    void insert(int index, int value)
    {
        if (index < 0 || index > size)
        {
            cout << "Index out of bounds!" << endl;
            return;
        }
        if (size == capacity)
        {
            expand();
        }
        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    // 删除指定位置的元素
    void erase(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    // 获取指定位置的元素
    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds!" << endl;
            return -1; // 返回一个默认值
        }
        return data[index];
    }

    // 修改指定位置的元素
    void set(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds!" << endl;
            return;
        }
        data[index] = value;
    }

    // 获取当前元素个数
    int getSize() const
    {
        return size;
    }

    // 打印顺序表
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    SeqList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.insert(1, 10);
    list.print();

    list.erase(2);
    list.print();

    cout << "Element at index 1: " << list.get(1) << endl;
    list.set(1, 99);
    list.print();

    return 0;
}
