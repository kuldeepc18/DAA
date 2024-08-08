#include <stdio.h>
#include <string.h>

#define d 10

// Function to implement the Rabin-Karp algorithm for pattern searching
void rabinKarp(char pattern[], char text[], int q)
{
    // Get the length of the pattern and the text
    int m = strlen(pattern);
    int n = strlen(text);

    // Declare variables for hash values, hash constant, and loop counters
    int i, j;
    int p = 0; // hash value for the pattern
    int t = 0; // hash value for the current window in text
    int h = 1; // hash value for d^(m-1)

    // Calculate the hash value for d^(m-1) in d-ary system
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash values for the pattern and the first window of text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the pattern in the text using sliding window technique
    for (i = 0; i <= n - m; i++)
    {
        // Check if the current hash values of the pattern and window match
        if (p == t)
        {
            // If hash values match, verify characters one by one
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If all characters match, the pattern is found at the current position
            if (j == m)
                printf("Pattern is found at position: %d \n", i + 1);
        }

        // Calculate hash value for the next window in text
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Ensure t is non-negative for modular arithmetic
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    // Text and pattern to be searched
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";

    // A prime number used for modular arithmetic (usually a large prime)
    int q = 13;

    // Call the rabinKarp function to search for the pattern in the text
    rabinKarp(pattern, text, q);

    return 0;
}
