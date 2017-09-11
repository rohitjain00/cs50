#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //getting a string from user
    printf("Name : ");
   string name= get_string();
   
    if (name[0] !=32 ){
           printf("%c",toupper(name[0]));
       }
    //for every word in the name
   for(int i=0,n=strlen(name);i<n;i++)
   {
        int j = 1;
        //if name ith char is space and i+jth char is not then
          if (name[i] == 32 && name[i+j] != 32){
              printf("%C",toupper(name[i+j]));
              }
              j++;
      
   }
   printf("\n");
}