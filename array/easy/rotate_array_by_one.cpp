#include <iostream>

void rotate(std::vector<int> &arr)
{
    int size = arr.size();

    // when rotating to right
    // for (int i = 0; i < size - 1; i++)
    // {
    //     std::swap(arr[i], arr[i + 1]);
    // }
    // when rotating to left
    for (int i = size - 1; i > 0; i--)
    {
        std::swap(arr[i], arr[i - 1]);
    }
}

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::vector<int> v;
    v.push_back(8);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);

    rotate(v);
    std::cout << "ans: ";
    print(v);
    return 0;
}