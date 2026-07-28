#include <iostream>

void insertAtBottom(std::stack<int> &stack, int element)
{
    if (stack.empty())
    {
        stack.push(element);
        return;
    }

    int temp = stack.top();
    stack.pop();
    insertAtBottom(stack, element);
    stack.push(temp);
}

void reverseStack(std::stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int element = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, element);
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
    stk.push(5);
    stk.push(4);
    stk.push(3);
    stk.push(2);
    stk.push(1);

    print(stk);
    reverseStack(stk);
    print(stk);

    return 0;
}

// https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=PROBLEM