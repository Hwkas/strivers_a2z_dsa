#include <iostream>

// my approach
// int *printDivisors(int n, int &size)
// {
//     int *arr = new int[100];

//     for (int i = 1; i <= n / 2; i++)
//     {
//         if (n % i == 0)
//         {
//             arr[size++] = i;
//         }
//     }
//     arr[size++] = n;
//     return arr;
// }

// Optimal approach
int *printDivisors(int n, int &size)
{
    int *arr = new int[100];
    int sqrtN = sqrt(n);

    for (int i = 1; i <= sqrtN; ++i)
    {
        if (n % i == 0)
        {
            arr[size++] = i;
            if (i != n / i)
            {
                arr[size++] = n / i;
            }
        }
    }
    std::sort(arr, arr + size);
    return arr;
}

void print(int *&arr, int &size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] ";
}

int main()
{
    int size = 0;
    int *arr = printDivisors(10, size);
    std::cout << "ans: ";
    print(arr, size);
    return 0;
}

// https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188