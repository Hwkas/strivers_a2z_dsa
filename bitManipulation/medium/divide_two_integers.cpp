#include <iostream>

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }

    bool negative_sign = (dividend < 0) != (divisor < 0);

    /*
    When the variable is of type int & it's value == INT_MIN, then abs conversion will not work.
    As the upper bound of storing positive value in int type is 2^31-1.
    So we need to type cast the variable to long & then get the abs of that int.
    */
    long numerator = abs((long)dividend);
    long denominator = abs((long)divisor);

    long quotient = 0;
    while (numerator >= denominator)
    {
        int i = 0;
        while (numerator >= (denominator << (i + 1)))
        {
            i += 1;
        }
        numerator -= (denominator << i);
        quotient += 1 << i;
    }

    if (quotient == INT_MIN)
    {
        return (negative_sign) ? INT_MIN : INT_MAX;
    }
    return negative_sign ? -quotient : quotient;
}

int main()
{
    int dividend = -2147483648, divisor = -1, quotient = 0;
    quotient = divide(dividend, divisor);
    std::cout << "quotient: " << quotient << std::endl;
    return 0;
}

// https://leetcode.com/problems/divide-two-integers/description/?envType=problem-list-v2&envId=bit-manipulation