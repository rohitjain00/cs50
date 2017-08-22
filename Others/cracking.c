#include<stdio.h>
#include <cs50.h>
#include <crypt.h>


char Forloop (int maxchar);
char alphabets[52];


int main (void)
{
    for(int i='a',j=0,k='A';j<26;i++,j++,k++){
        alphabets[j]=i;
    }
    for(int i='A',j=26;j<52;i++,j++){
        alphabets[j]=i;
    }   
    
    printf("%c\n",Forloop(10));
}

char Forloop (int maxchar)
{
    if(maxchar>0)
    {
        for(int j=0;j<maxchar;j++)
        {
            char guess[j];
        for(int i=0;i<52;i++)
        {
            guess[j]= alphabets[i];
            printf("%c\n",guess[j]);  
        }
            return(Forloop(maxchar-1));
        }
    }
        return 0;
}