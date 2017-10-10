#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int largest(int arr[], int n)
{
    int i;

    // Initialize maximum element
    int max = arr[0];

    // Traverse array elements from second and
    // compare every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int main() {
    int t;
    scanf("%d\n",&t);
    for (int j = 0 ; j< t ;j ++)
    {
        int *ar = malloc(sizeof(int) * 2);
        for(int i = 0; i < 2; i++){
           scanf("%i",&ar[i]);
        }
        int *A = malloc(sizeof(int) * 2);
        for(int i = 0; i < ar[0]; i++){
           scanf("%i",&A[i]);
        }
        int *Magic = malloc(sizeof(int) * 2);
        for(int i = 0; i < ar[1]; i++){
           scanf("%i",&Magic[i]);
        }
        int max = largest(A,ar[0]);
        int max1 = largest(Magic,ar[1]);
        int a = max;
        int first = 2, second = 7, next, c, bad[a+2];

           for ( c = 0 ; c < a ; c++ )
           {
              if ( c <= 1 )
                 next = c;
              else
              {
                 next = first + second;
                 first = second;
                 second = next;
              }
              bad[c] = next;
           }
     for (int j = 0; j<max ; j++)
     {
             for (int i = 0; i<ar[1] ; i++)
             {
                 if ( bad[j] == Magic[i])
                 {
                     bad[j] = 0;
                 }
             }
        }

        int friends = 0;
        for (int i = 0; i<ar[0] ; i++)
        {
            int count = 0;

            for (int j = 0; j<max ; j++)
            {
                if (A[i] == bad[j] && (i != 0 || i != ar[0]-1))
                {
                    friends -= 2;
                    break;
                }
                else if (A[i] == bad[j] && (i == 0 || i == ar[0]-1))
                {
                    friends -= 1;
                    break;
                }
                else if (A[i] != bad[j])
                {
                   count++;
                    break;
                }

            }
            if (count > 0)
            {
                friends++;
            }
        }

        printf("%d\n",friends);
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
