#include <stdio.h>
#include <cs50.h>
//user will input the amount of minutes he take to shower and the program wil tel how much bottles of water is he using to shower daily
int main(void)
{
    int minutes;
   do {
       printf("minutes ");
       minutes = get_int();
   }
   while(minutes <= 0);
    
    printf("bottles : %i\n", minutes * 12);    
}