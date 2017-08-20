#include <stdio.h>
#include <cs50.h>

long long factorial (long long n);

int main (void)
{
    int number = get_int();
    printf("%lld",factorial(number));   
}

long long factorial (long long n)
{
    if (n<0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    if (n>1){
        return(n * factorial(n-1));
    }
    return 0;
}