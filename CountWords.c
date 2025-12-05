#include <stdio.h>
#include <string.h>

int countWords(char str[]) {
    int count = 0, i = 0;

    // skip leading spaces
    while (str[i] == ' ') {
        i++;
    }

    while (str[i] != '\0') {
        // if a space is followed by a non-space character, it's a new word
        if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0') {
            count++;
        }
        i++;
    }

    // add 1 for the last word (if string is not empty)
    if (i > 0)
        count++;

    return count;
}

int main() {
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int words = countWords(str);

    printf("Number of words = %d\n", words);

    return 0;
}