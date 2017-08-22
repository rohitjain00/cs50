#include<stdio.h>
#include<cs50.h>


int valid_triangle(int a,int b,int c);

int main(void)
{
    //getting triangle side from user
    int i = get_int();
    int j = get_int();
    int k = get_int();
    
    //calling a function
    int c = valid_triangle(i,j,k);
    
    //if c is true then print out valid triangle
    if(c){
    printf("Ä valid Triangle");
    }
    //else print out invalid triangle
    else{
        printf("no this cant a make a triangle");
    }
    //for new line and fun
    printf("\nThanks For Playing\n");
        
}
//defining a functions
int valid_triangle(int a,int b,int c)
{
    //check if side entered is not negative
    if (a<=0 || b<=0 || c<=0){
        return false;
    }
    //checking the property of triangle
    if (a+b<c && b+c<a && c+a<b){
        return false;
    }
    return true;
}