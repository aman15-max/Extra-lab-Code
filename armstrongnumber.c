//check whether a number is an armstrong number.

#include <stdio.h>
void main(){
    int n,r,c,sum,temp;
    printf("Enter the value of n\n");
    scanf("%d",n);
    temp=n;
    while (n>0)
    {
    r=n%10;
    c=r*r*r;
    sum=sum+c;
    n=n/10;
    n=temp;
    }
    if(n==sum){
        printf("It is Armstrong");
    } else("It is not Armstrong");}
    



