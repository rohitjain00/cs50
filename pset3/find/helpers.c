/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // if negative then return false
    if (n < 0)
    {
    return false;
    }
    //hence if positive then
    else
    {
        int start = 0;
        int end = n;

        for (int i =0,j=log(n)/log(2);i<j;i++)
        {

          if (values[(end+start)/2] > value)
            {
                if (end<=start)
                {
                    return false;
                }

                end = (end+start)/2;
            }

            if (values[(end+start)/2] < value)
            {
                if (end<=start)
                {
                    return false;
                }

                start = (end+start)/2;
            }
            if (values[(end+start)/2] == value)
            {
                return true;
            }
        }

        return false;
    }
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int MAX = n;
    // TODO: implement a sorting algorithm

    //for max-1 time do the following loop
    for(int k=0;k<MAX-1;k++){
        int swap = 0;
        for (int i=0,j=1;j<MAX+1;i++,j++)
        {
            int temp = values[i];
            if (values[i]>values[j]){
                values[i] = values[j];
                values[j] = temp;
                swap++;
            }
        }
        if(swap == 0){
            break;
        }
    }
}


