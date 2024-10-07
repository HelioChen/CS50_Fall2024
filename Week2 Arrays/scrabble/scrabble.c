#include <stdio.h>
#include <cs50.h>
#include <string.h>

int sum_score(string name);

int score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main()
{
    string name1 = get_string("Player 1: ");
    string name2 = get_string("Player 2: ");

    int score1 = sum_score(name1);
    int score2 = sum_score(name2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else printf("Tie!\n");
}

int sum_score(string name)
{
    int sum = 0;

    int k = strlen(name);
    for (int i = 0; i < k; i ++ )
    {
        if (name[i] >= 'A' && name[i] <= 'Z')
        {
            sum += score[name[i] - 'A'];
        }
        else if (name[i] >= 'a' && name[i] <= 'z')
        {
            sum += score[name[i] - 'a'];
        }
    }

    return sum;
}
