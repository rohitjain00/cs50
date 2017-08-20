#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    int number = get_int();
    
    int length = (int)floor(log10((float)number)) + 1;
    
    char * arr [length];
    
    int i = 0;
    
    do {
        arr[i] = number % 10;
        
        number /= 10;
        i++;
    } 
    while (number != 0);
    
    for (i = 0; i < length; i++) {
        printf("\narr[%d] = %d", i, arr[i]);
   }
    
}