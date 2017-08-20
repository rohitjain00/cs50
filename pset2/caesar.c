#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]){
    //convert the string into number of the number user provided
    int arg1 = atoi(argv[1]);
    //to make sure that number is less than 26
   arg1 = arg1 % 26;
    //if user input 2 char
    if (argc == 2){
        //ask for text
        printf("plaintext: ");
        //get string
        string p = get_string();
        //loop that does it all
        
        printf("ciphertext: ");
        
        for(int i=0,n=strlen(p);i<n;i++){
     
            //for small letters
            if(p[i]>=97){
            
            if(p[i]+arg1 > 122 ){
            p[i] = 97 + arg1 -(123-p[i]);
        }
        else{
            p[i] +=arg1;
        }
        
        }
        //for capitals letters
        if (p[i]>=65 && p[i] <=90){
            
            if(p[i]+arg1 > 90 ){
            p[i] = 65 + arg1 -(91-p[i]);
        }
        else{
            p[i] +=arg1;
        }
        
        }
        //for printing the string p
        printf("%c",p[i]);
        }
        printf("\n");
        exit (0);
    }
    else{
        exit(1);
    }
}