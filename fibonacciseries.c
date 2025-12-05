//Print the fibonacci series of n terms


#include <stdio.h>
int main() {
    int n,a=0,b=1,c;
    printf("Enter the number to print the fibonacci series");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d",a);
        c=a+b;
        a=b;
        b=c;
    
}
return 0;
}
   