#include<stdio.h>
#include<cs50.h>
#include<stdio.h>

int main(void)
{
    printf("O hai! How much change is owed?\n");
    float change = get_float();
    
    int coins = 0;
    
    for (float i = change;i>=0.25;i = i-0.25) { 
    coins++;
    change = change-0.25;
 
    };
    for (float i = change;i>=0.10;i = i-0.10) { 
    coins++;
    change = change-0.10;
 
    };
    for (float i = change;i>=0.05;i = i-0.05) { 
    coins++;
    change = change-0.05;
 
    };
    for (float i = change;i>=0.01;i = i-0.01) { 
    coins++;
    change = change-0.01;
        };
    printf("coins to give %.i\n", coins);
}