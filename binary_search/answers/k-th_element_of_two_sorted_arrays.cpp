#include <iostream>

int kthElement(std::vector<int> &arr1, std::vector<int> &arr2, int n, int m, int k)
{
    if (m < n)
    {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = std::max(0, (k - m)), high = std::min(k, n);

    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

        int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == n) ? INT_MAX : arr2[cut2];

        if ((left1 <= right2) && (left2 <= right1))
        {
            return std::max(left1, left2);
        }

        if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> arr1 = {2, 3, 45};
    std::vector<int> arr2 = {4, 6, 7, 8};
    int k = 4;
    std::cout << "K-th Element of Two Sorted Arrays is " << kthElement(arr1, arr2, arr1.size(), arr2.size(), k) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159?leftPanelTabValue=SUBMISSION