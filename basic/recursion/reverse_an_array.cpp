#include <iostream>

// my approach
// void solve(std::vector<int> &arr, int n)
// {
//     if (n == 0)
//     {
//         arr[n] = arr[arr.size() - 1];
//         return;
//     }
//     int element = arr[arr.size() - n];
//     solve(arr, n - 1);
//     arr[n - 1] = element;
// }

void solve(std::vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        std::swap(arr[start], arr[end]);
        solve(arr, start + 1, end - 1);
    }
}

void reverseArray(std::vector<int> &arr)
{
    // solve(arr, arr.size());
    solve(arr, 0, arr.size() - 1);
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
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    reverseArray(arr);

    std::cout << "ans: ";
    print(arr);
    return 0;
}

// https://www.geeksforgeeks.org/problems/reverse-an-array/1