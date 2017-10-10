#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int countSetBits(unsigned int n)
{
  unsigned int c;
  for (c = 0; n; n >>= 1)
  {
    c += n & 1;
  }
  return c;
}
int is_prime(int num);

int next_pr(int num){
    int c;
    if(num < 2)
        c = 2;
    else if (num == 2)
        c = 3;
    else if(num & 1){
        num += 2;
        c = is_prime(num) ? num : next_pr(num);
    }
    else
        c = next_pr(num-1);

    return c;
}

int is_prime(int num){
    if((num & 1)==0)
        return num == 2;
    else {
        int i, limit = sqrt(num);
        for (i = 3; i <= limit; i+=2){
            if (num % i == 0)
                return 0;
        }
    }
    return 1;
}

int main(void)
{
  int n;
  scanf("%u\n", &n);
    int numbers[n][2];

        for (int i = 0; i<n ; i++)
        {
            for (int j = 0; j< 2 ; j++){
            scanf("%d",&numbers[i][j]);
            }
        }

    int power[n];
        for (int i = 0; i<n ; i++){power[i] = 0;}



    for (int i = 0; i<n ; i++){
        for (int j = numbers[i][0] ; j <= numbers[i][1]; j++)
        {
            power[i] += countSetBits(j);
        }
    }


    int div[n];
    for (int i = 0; i<n ; i++)
    {
        div[i] = 0;
    }

    for (int i = 0; i<n ; i++)
    {
        for (int j = 1; j < power[i] + 1; j++)
        {
            if (power[i] % j == 0)
            {
                div[i]++;
            }
        }
    }

    for (int i = 0; i<n ; i++){
        if (! is_prime(power[i])){
            power[i] = next_pr(power[i]);
        }
    }

    int effort[n];

    for (int i = 0; i<n ; i++){
        effort[i] = power[i] * div[i];
    }
     for (int i = 0; i<n ; i++){
         printf("%d\n", effort[i]);

     }

    return 0;
}
