//Count the number of words in the string.

#include <stdio.h>
int main() {
    char str[30];
    int i, c = 0;

    printf("Enter String:\n");
    fgets(str, sizeof(str), stdin);   

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {   
            c++;
        }
    }

    printf("words = %d\n", c + 1);  
    return 0;
}
