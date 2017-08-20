#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //getting a string from user
   string name= get_string();
    //printing the first letter
    printf("%C",toupper(name[0]));
    
    //for every word in the name
   for(int i=0,n=strlen(name);i<n;i++)
   {
       //if the ith word of name is space then
        if (name[i] == 32)
        {
            printf("%c",toupper(name[i+1]));
        }
   }
   printf("\n");
}