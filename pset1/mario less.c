#include <stdio.h>
#include <cs50.h>


int main(void)
{
        int i;
        int c;
        int tmp;
         int height;
         
        do {printf("height : ");
        height = get_int();
        height = height+1;
        }
        while(height>24 || height<0);
        tmp=height;
        
            for(c = 1;c < height;c++){
         
      for( i = tmp-2; i>0 ;i--) {
            printf(" ");
         }
      for (int j = 0; j<=c;j++) {
            printf("#");
      }
      tmp=tmp-1;
        printf("\n");
      }
      
}