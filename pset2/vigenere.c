#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]){
    
    string key = argv[1];
    bool all_alphabets =false;
    
    //to check if the key input are all alphabetical
    for (int a=0,n=strlen(argv[1]);a<n;a++){
        
        char q = argv[1][a];
        
        if( (q>='a' && q<='z') || (q>='A' && q<='Z')){
          all_alphabets= true;
        }
        
    }
        if (all_alphabets ==false ){
            printf("please enter a valid key!!\n");
        }
    
    
    if(argc == 2){
        //defining array of lenth of argv [1]
        if (all_alphabets){
        int k[strlen(argv[1])];
        //for loop to arrange all in array
    for(int j=0,n=strlen(argv[1]);j<n;j++){
        
        if(argv[1][j]>64 && argv[1][j]<91){
            k[j] = argv[1][j]-64;
        }
        if(argv[1][j]>'a' && argv[1][j]<'z'){
            k[j] = argv[1][j]-96;
        }
        }
    
        printf("plaintext: ");
        //get string
        string p = get_string();
        //loop that does it all
        
        printf("ciphertext: ");
        
        for (int i = 0, j = 0, g = strlen(p); i < g; i++, j++)
        {
            if (j > strlen(key) - 1)
            {
                j = 0;
            }
                int c = 0;
                //Check case of text alphabet
                //Assign it an alphabet number and code it in cyphertext
                if (isupper(p[i])) // if the ith cahr of p is upper
                {
                    c = (((p[i] - 65) + (tolower(key[j]) - 97))%26) + 65;
                    printf("%c", (char)c);
                }
                else if (islower(p[i])) // if the ith cahr of p is lower
                {
                    c = (((p[i] - 97) + (tolower(key[j]) - 97))%26) + 97;
                    printf("%c", (char)c);
                }
                else
                {
                    printf("%c", p[i]);
                    j--;
                }
            } 
            printf("\n");
            return 0;
        }
    }
        else if(argc != 2) {
            printf("PLEASE ENTER A VALID KEY!!\n");
            return 1;
        }
        
}


