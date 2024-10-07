#include <stdio.h>
#include <cs50.h>

int main()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j < n - i; j ++ )
        {
            printf(" ");
        }
        for (int k = 0; k < i; k ++ )
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
