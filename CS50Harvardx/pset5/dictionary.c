/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 * Tjitske Lohstroh
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    // it has a bool stating if it is a word or not
    bool is_word; 
    // it has 27 pointers that point to children nodes
    struct node* children [27];
}
node;

node* root;
int wordcounter;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    
    int wordSpot = 0;
    int childSpot = 0;
    
    node * pointer = root;
    
    if (root == NULL)
    {
        return false;
    }
    
    while (word[wordSpot] != '\0')
    {
        // look at the current letter
        char curLetter = word[wordSpot];
        
        // convert current letter to lower case if it is alpha & upper case.
        if (isalpha (curLetter) && isupper(curLetter))
        {
            curLetter = tolower(curLetter);
        }
        
        // figure out what "spot" is.
        if (curLetter == '\'')
        {
            childSpot = 26;
        }
        else
        {
            childSpot = (curLetter - 'a');
        }
        
        
        
        if (pointer->children[childSpot] != NULL)
        {
            // update pointer to next node
            pointer = pointer->children[childSpot];
            
        }
        else
        {
            return false;
            
        }
        
        wordSpot++;
       
    } 
    return pointer->is_word;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Open dictionary file
    FILE * fp = fopen (dictionary, "r");
    // Check for NULL
    if (fp == NULL)
    {
        fclose(fp);
        printf("not able to open %s.\n", dictionary);
        return false;
    }
    
    root = NULL;
    wordcounter = 0;
    int spot;
    
    // Look at first letter to check if there are words in the dictionary
    char firstLetter = fgetc(fp);
    if (firstLetter == EOF)
    {
        printf("dictionary is empty!\n");
        return false;
    }
    
    
    // Look at root node and check if root is null
    if (root == NULL)
    {
        // Make array [27](and "fill it")
        node* newnode = malloc (sizeof(node));
            
        // check if malloc worked
        if (newnode == NULL)
        {
            printf("not able to load %s. \n", dictionary);
            fclose(fp);
            return false;
        }    
                
        // make children point to null
        for (int i = 0; i < 27; i++)
        {
            newnode->children[i] = NULL;
        }
            
        newnode->is_word = false;
      
        // make root point to the first newnode
        root = newnode;
    }
        
    node* pointer = root;
    
    for (char curLetter = firstLetter; curLetter != EOF; curLetter = fgetc(fp))
    {  
          
        // calculate where the current letter or appstrohe go
        if (curLetter == '\'')
        {
            spot = 26;
        }  
        else
        {
            spot = (curLetter - 'a');
        } 
        
            
        // als curLetter = /n dan: bool is_word = tue
        if (curLetter == '\n') 
        {
            // bool is_word is true
            pointer->is_word = true;
            // updte wordcounter
            wordcounter++;
            // reset pointer to root
            pointer = root;
        }
        
        else
        {
            // If spot points to NULL , create new node.
            if (pointer->children[spot] == NULL)
            {
                node * newnode = malloc (sizeof(node));
                // check if malloc worked
                if (newnode == NULL)
                {
                    printf("not able to load %s. \n", dictionary);
                    fclose(fp);
                    return false;
                }
                // make children point to null and set bool to false
                for (int i = 0; i < 27; i++)
                {
                    newnode->children[i] = NULL;
                }
                newnode->is_word = false;
            
                // make spot point to newnode
                pointer->children[spot] = newnode;
            }
            
            // if spot is not NULL make pointer point to the node "spot" points to.
            pointer = pointer->children[spot];
           
        }
            
           
    }
    
    
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size()
{
    return wordcounter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */



bool freeTrie(node* pointer)

{
    for(int i = 0; i < 27; i++)
    {
        if (pointer->children[i] != NULL)
        {
            freeTrie(pointer->children[i]);
        }
    }
    free(pointer);
    
    return true;
}

bool unload(void)
{
    return freeTrie(root);
}
