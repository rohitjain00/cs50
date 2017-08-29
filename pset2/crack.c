#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <cs50.h>


int main(int argc , string argv[])
{
    if (argc == 2){
    string hash = argv[1];
    char alphabets[53];

    //making the first element to be empty so that all possible values upto 4 can be crypted and checked
     alphabets[0]= \0;
    //arrange all the possible alphabets in an array
    for(int i='a',j=1,k='A';j<27;i++,j++,k++){
        alphabets[j]=i;
    }
    for(int i='A',j=27;j<53;i++,j++){
        alphabets[j]=i;
    }

    //making the guess
    char guess[4];
    //set the first to a
    for(int j=0;j<52;j++){

        //start the secdond loop
        for(int i=0;i<52;i++){

            //start the 3rd loop
            for(int k=0;k<52;k++){

                //start the last loop
                for(int l=0;l<52;l++){

                    //all possible 4 word outputs
                    guess[0] = alphabets[j];
                    guess[1] = alphabets[i];
                    guess[2] = alphabets[k];
                    guess[3] = alphabets[l];

                    string result = crypt(guess, "50");

                    //if the string result and hash are same then
                    if (strcmp(result, hash)==0){
                        printf("%s\n",guess);
                        exit(0);
                    }
                }
            }
        }
    }
}

    else{
        printf("./crack hash\n");
    }


}

