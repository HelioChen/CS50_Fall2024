#include <stdio.h>
#include <cs50.h>

int main()
{
    // 题目要求用get_long,如果使用string(char *)的话后面验证开头两位数会简单很多
    long a = get_long("Number: ");

    int sum = 0;
    int length = 0;
    long tmp = a;

    while (tmp)
    {
        int digit = tmp % 10;
        if (length % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            digit *= 2;
            sum += digit % 10 + digit / 10;
        }
        tmp /= 10;
        length ++ ;
    }

    // 直接用数字存的弊端，计算数字中的每一位不如使用string方便
    if (sum % 10 == 0)
    {
        if (length == 15 && (a / 10000000000000 == 34 || a / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (a / 100000000000000 >= 51 && a / 100000000000000 <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 && a / 1000000000000 == 4) || (length == 16 && a / 1000000000000000 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
