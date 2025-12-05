//Swap two numbers using a third variable / pointers

#include <stdio.h>
void swap(int *x,int *y){
    int c;
    c=*x;
    *x=*y;
    *y=c;
}

 int main(){
    int a,b;
    printf("Enter the two numbers a and b \n");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("a=%d and b=%d",a,b);
    return 0;
    
}
   