#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digit(string a);

int main(int argc, string argv[])
{
    if (argc != 2) return 1;
    if (!only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);
    string s = get_string("plaintext: ");
    int l = strlen(s);

    printf("ciphertext: ");
    for (int i = 0; i < l; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')  // 小写字母加密
        {
            printf("%c", ((s[i] - 'a' + k) % 26) + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')  // 大写字母加密
        {
            printf("%c", ((s[i] - 'A' + k) % 26) + 'A');
        }
        else  // 非字母字符保持不变
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}

bool only_digit(string a)
{
    int l = strlen(a);
    bool flag = true;
    for (int i = 0; i < l; i ++ )
    {
        if (!isdigit(a[i]))
        {
            flag = false;
            break;
        }
    }
    return flag;
}
