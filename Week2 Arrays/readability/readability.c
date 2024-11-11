#include <stdio.h>
#include <cs50.h>
#include <string.h>

int count_words(string a);
int count_letters(string a);
int count_sentences(string a);

int main()
{
    string a = get_string("Text: ");

    int w = count_words(a);
    int l = count_letters(a);
    int s = count_sentences(a);

    double index = 0.0588 * l * 100 / w - 0.296 * s * 100 / w - 15.8;

    if (index <= 1) printf("Before Grade 1\n");
    else if (index >= 16) printf("Grade 16+\n");
    else printf("Grade %.0lf\n", index);

    return 0;
}

int count_words(string a)
{
    int cnt = 0;
    int l = strlen(a);
    for (int i = 0; i < l; i ++ )
    {
        if (a[i] == ' ') cnt ++ ;
    }
    return cnt + 1;
}

int count_letters(string a)
{
    int cnt = 0;
    int num = count_words(a);
    int l = strlen(a);
    for (int i = 0; i < l; i ++ )
    {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) cnt ++ ;
    }
    return cnt;
}

int count_sentences(string a)
{
    int cnt = 0;
    int num = count_words(a);
    int l = strlen(a);
    for (int i = 0; i < l; i ++ )
    {
        if (a[i] == '.' || a[i] == '?' || a[i] == '!') cnt ++ ;
    }
    return cnt;
}
