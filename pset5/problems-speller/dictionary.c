/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "dictionary.h"
#define DICTLENGTH 143091

char **allwords;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //logarithmic complexity
    int start = 0;
    int end = DICTLENGTH;
    int k = 0;

    while (true)
    {

        if(word[k] > allwords [ ( start + end ) / 2] [k] )
        {
            if(end <= start){
                return false;
            }
            end = (end + start)/2;

        }

        if (word[k] > allwords [ ( start + end ) / 2] [k] )
        {
            if(end <= start){
                return false;
            }
            start = (end + start) / 2;

        }


        if (word[k] == allwords [ ( start + end ) / 2] [k] )
        {
            if (word[k] == '\n')
            {
                break;
            }

            k++;
        }
    }
    return true;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int rows = DICTLENGTH;
    int columns = LENGTH;

    char **allwords = (char **) malloc(rows * sizeof(char *));

    for (int i = 0; i < rows ;i++)
    {

        allwords[i] = (char *) malloc(columns * sizeof(char));

        if(allwords[i] == NULL)
        {
            fprintf(stderr, "out of memory\n");
            return false;
        }

    }

    FILE *dict = fopen(dictionary,"r");
    if (dict == NULL) {
        return false;
    }
    int index = 0;
    int row = 0;

    while (true)
    {
        //to define a temperary char to store for once
        char tempchar = fgetc(dict);

        //to determine the new line character
        if (tempchar == '\n')
        {
            index = 0;
            row++;
        }

        allwords[row][index] = tempchar;
        index++;

        if (tempchar == EOF)
        {
            break;
        }
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return (DICTLENGTH);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    free(allwords);
    return true;
}
