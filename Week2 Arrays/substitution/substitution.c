#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cnt[26];
char alpha[26];

bool alphabet(string s);
bool only_once(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26 || !alphabet(argv[1]) || !only_once(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int k = strlen(argv[1]);
    for (int i = 0; i < k; i ++ )
    {
        alpha[i] = argv[1][i];
    }

    string s = get_string("plaintext：");
    int l = strlen(s);

    printf("ciphertext: ");
    for (int i = 0; i < l; i ++ )
    {
        if (islower(s[i])) printf("%c", tolower(alpha[s[i] - 'a']));
        else if (isupper(s[i])) printf("%c", toupper(alpha[s[i] - 'A']));
        else printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}

bool alphabet(string s)
{
    bool flag = true;

    int n = strlen(s);
    for (int i = 0; i < n; i ++ )
    {
        if (!isalpha(s[i]))
        {
            flag = false;
            return flag;
        }
    }

    return flag;
}

bool only_once(string s)
{
    bool flag = true;

    int n = strlen(s);
    for (int i = 0; i < n; i ++ )
    {
        s[i] = toupper(s[i]);
        cnt[s[i] - 'A'] ++ ;
    }

    for (int i = 0; i < 26; i ++ )
    {
        if (cnt[i] > 1) flag = false;
    }

    return flag;
}
