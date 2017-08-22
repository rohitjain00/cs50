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

        for(int i =0,j=log(n)/log(2);i<j;i++)
        {

        if(values[(end+start)/2] > value){
            if(end<=start){
                return false;
            }
            end = (end+start)/2;
        }

        if(values[(end+start)/2] < value){
            if(end<=start){
                return false;
            }
            start = (end+start)/2;
        }
        if(values[(end+start)/2] == value){
            return true;
            exit(0);
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

    // TODO: implement a sorting algorithm
    int temp[65536] = {0};
    for (int i=0;i<n;i++){
        temp[values[i]] += 1;
    }
    for (int i=0,k=0;i<n;i++,k++){
        if(temp[k] !=0){
            for (int j = 0;j<temp[k];j++){
                values[i+j] = k;
                i++;
            }
        }
    }
}



