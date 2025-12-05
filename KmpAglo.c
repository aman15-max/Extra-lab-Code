#include <stdio.h>
#include <string.h>

// Function to create LPS (Longest Prefix Suffix) array
void computeLPSArray(char *pat, int M, int lps[]) {
    int len = 0;          // length of the previous longest prefix suffix
    lps[0] = 0;           // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Go to previous longest prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];   // Continue searching for next match
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char txt[100], pat[100];

    printf("Enter text (no spaces): ");
    scanf("%s", txt);

    printf("Enter pattern (no spaces): ");
    scanf("%s", pat);

    KMPSearch(pat, txt);

    return 0;
}

