/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "dictionary.h"
#define DICTLENGTH 143091
#define LENGTH 45

char **allwords;

    struct LinkedList{
        int data;
        struct LinkedList *next;
        };
typedef struct LinkedList *node;

node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}

node addNode(node head, int value){
    node temp,p;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value; // add element's value to data part of node

    if(head == NULL){
        head = temp;     //when linked list is empty
    }

    else{
        p  = head;//assign head to p
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }

    return head;
}
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
