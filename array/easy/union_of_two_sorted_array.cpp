#include <iostream>

std::vector<int> findUnion(std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::vector<int> ans;
    int size1 = arr1.size(), size2 = arr2.size();
    int i = 0, j = 0;

    while (i < size1 && j < size2)
    {

        if (arr1[i] <= arr2[j])
        {
            if ((ans.size() == 0) || (ans.back() < arr1[i]))
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if ((ans.size() == 0) || (ans.back() < arr2[j]))
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < size1)
    {
        if ((ans.size() == 0) || (ans.back() < arr1[i]))
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < size2)
    {
        if ((ans.size() == 0) || (ans.back() < arr2[j]))
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
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
    std::vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(5);

    std::vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(4);
    arr2.push_back(4);
    arr2.push_back(5);

    std::vector<int> ans = findUnion(arr1, arr2);
    std::cout << "ans: ";
    print(ans);
    return 0;
}

// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
