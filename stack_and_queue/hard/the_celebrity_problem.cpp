#include <iostream>

int findCelebrity(int n)
{
    int top = 0, down = n - 1;

    while (top < down)
    {
        if (knows(top, down))
        {
            top++;
        }
        else if (knows(down, top))
        {
            down--;
        }
        else
        {
            top++;
            down--;
        }
    }

    if (top > down)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        if (knows(top, i) || !knows(i, top))
        {
            return -1;
        }
    }

    return top;
}

int main()
{
    std::cout << findCelebrity(2) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/the-celebrity-problem_982769