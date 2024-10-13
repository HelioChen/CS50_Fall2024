#include <stdio.h>
#include <cs50.h>

int main()
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n <= 0);

    int cnt = 0;
    cnt += n / 25;
    n %= 25;
    cnt += n / 10;y
    n %= 10;
    cnt += n / 5;
    n %= 5;
    cnt += n / 1;

    printf("%d\n", cnt);

    return 0;
}
