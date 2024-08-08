#include <stdio.h>
#include <string.h>

int main()
{
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";

    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int j;
    for (int i = 0; i <= text_length - pattern_length; i++)
    {
        for (j = 0; j <= pattern_length; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == pattern_length)
            printf("%d ", i);
    }
    return 0;
}