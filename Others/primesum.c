#include <stdio.h>

int main (void)
{
    printf("Input the number");
    int number;
    scanf("%d",&number);

    int prime[number/2];
    int w = 0;
    for (w = 0; w < number/2; w++)
    {
        prime[w] = 0;
    }

    int a = 0;
    int i = 0;
    int j = 0;
    int count;

    for (i = 3; i < number ; i++)
    {
        count = 1;

        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                count = 0;
            }
        }

        if (count == 1)
        {
            prime[a] = i;
            a++;
        }
    }

    i = 0;
    j = 0;

    for (i = 0; i < number ; i++)
    {
        for (j = 0; j < i ; j++)
        {
            if (prime[i] + prime [j] == number)
            {
                printf("%d + %d = %d \n",prime[i],prime[j],number);
            }
        }
    }
    return 0;
}
