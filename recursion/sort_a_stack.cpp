#include <iostream>

// Striver's Solution
// void insert(std::stack<int> &s, int temp)
// {
//     if (s.empty() || s.top() <= temp)
//     {
//         s.push(temp);
//         return;
//     }

//     int val = s.top();
//     s.pop();
//     insert(s, temp);
//     s.push(val);
// }

// void sortStack(std::stack<int> &stack)
// {
//     if (!stack.empty())
//     {
//         int temp = stack.top();
//         stack.pop();

//         sortStack(stack);

//         insert(stack, temp);
//     }
// }

// My Solution
void insertAtCorrectPlace(std::stack<int> &stack, int element)
{
    if ((!stack.empty()) && (element < stack.top()))
    {
        int temp = stack.top();
        stack.pop();
        insertAtCorrectPlace(stack, element);
        stack.push(temp);
    }
    else
    {
        stack.push(element);
    }
}

void sortStack(std::stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int element = stack.top();
    stack.pop();
    sortStack(stack);
    insertAtCorrectPlace(stack, element);
}

void print(std::stack<int> stk)
{
    std::cout << "[";
    while (!stk.empty())
    {
        std::cout << stk.top() << ((stk.size() > 1) ? ", " : "");
        stk.pop();
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::stack<int> stk;
    stk.push(3);
    stk.push(-7);
    stk.push(9);
    stk.push(-2);
    stk.push(5);

    print(stk);
    sortStack(stk);
    print(stk);

    return 0;
}

// https://www.naukri.com/code360/problems/sort-a-stack_985275