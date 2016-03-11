/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"

//prototype 
typedef struct node
{
    bool is_word;
    struct node* children [27];// 26 of 27???? 0-26 = 
}
node;



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    // Open dictionary file
    FILE * fp = fopen (dictionary, "r")
    //Check for NULL
    if (fp ==NULL)
    {
        printf("not able to open %s.\n", dictionary)
        return false
    }
    
    // iterate over all the chars in the dictionary.
    // that stream looks like this: wordone\nwordtwo\nwordthree\nwordfour\nwordetc\n
    // thus it looks to me I can iterate over all the characters in on go and don't need some buffer for storing every word?
    
    int c = fgetc(fp)
    while (c != EOF)
    {
        if (c != /n)
        {
            // code for traversing the trie
            // (make sure you have a prototype for a trie-node!)
            // set first node to root
            node* root = malloc (sizeof (node));
            // set a pointer to keep track
            node* ptr_index = root???????????????????? //this stores the values of the current node.
            
            if(ptr_index->children[c -'a']==NULL)//if there are no children in current node yet (they point to null
            {
                // malloc new node
                // check if that went ok?!
            }
            else 
            {
                //NOTHING! WE DONT HAVE TO DO ANYTHING CUZ THE LETTER IS IN THE NODE!!
            }
            
        }
        else
        {
            // set is_word to true
            // set index back to root
        }
        
        //go to next letter (Maybe change this to a for loop later..)
        c = fgetc(fp)
    }
        
    
    
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
