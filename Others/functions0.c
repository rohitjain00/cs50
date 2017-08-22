#include<stdio.h>
#include<cs50.h>


int mult(int a,int b);

int main(void)
{
    //getting integer from user
    int a = get_int();
    int b = get_int();
    
    //calling a function
    int c = mult(a,b);
    printf("%i\n",c);
}
//defining a functions
int mult(int a,int b)
{
    int c = a*b;
    return c;
}