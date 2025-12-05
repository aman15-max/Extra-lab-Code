//Convert all lowercase characters in a string to uppercase.

#include <stdio.h>
#include <string.h>
int main() {
    char a[50];
    printf("Enter string in lower case\n");
    gets(a);
    printf("String in upper case=%s",strupr(a));
    return 0;
}
