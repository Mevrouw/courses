/**
 * vigenere.c
 *
 * Tjitske Lohstroh
 * Accepts keyword from user in commandline and encrypts input.
 * ci = (pi + kj) % 26
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Accept one command-line argument.
    // A keyword, k, composed entirely of alphabetical characters.
    if (argc != 2)
    {
        printf("You entered more than one key.\n");
        printf("Please restart and enter one key-word into the commandline\n");
        return 1;
    }
    
    string key = argv[1]; 
    int keyLength = strlen (key);
    int j = 0;

    // If non valid argument, complain and return 1
    for (int i = 0; i < keyLength; i++)
    {
        // If user entered non alphabetical caracters, yell!
        if (isalpha(key[i]) == false)
        {
            printf("You entered non alphabetical characters.\n");
            printf("Please restart and enter one key-word into the commandline\n");
            return 1;
        }
    }
    

    // As for the characters in key, you must treat A and a as 0, B and b as 1, … , and Z and z as 25
    for (int i = 0; i < keyLength ; i++)
    {  
        // convert uppers in key to 0 up to 25   
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            key[i] = key[i] - 'A'; 
        }
        // converts lowers in key to 0 up to 25
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] = key[i] - 'a'; 
        }
    }

    // Otherwise, prompt the user for a string of plaintext p 
    // printf ("Please type some text: \n");
    string p = GetString();

    // encrypt according to Vigenère’s cipher with k (c[i] = (p[i] + key[i]) % 26) 
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // If letter is alphabetical.
        if (isalpha (p[i]))
        {   
            // If letter is also uppercase
            if (isupper(p[i])) 
            {
                // prints cypher preserving upper
                // j modulo keylength!
                // because if the key is shorter than the text we need to start with Key[0] again.
                printf( "%c", (p[i] - 'A' + key[j %keyLength]) %26 + 'A' );
            }
            else
            {
                // prints cypher lowercase letters
                // j modulo keylength!
                // because if the key is shorter than the text we need to start with Key[0] again.
                printf( "%c", (p[i] - 'a' + key[j %keyLength]) %26 + 'a' );
            }
            
            // increment j only if p[i] was alphabetical   
            j++;
        }
      
      // keep non alphabetical unchanged (and j not incremented!)
        else
        {
            printf ("%c", p[i]);
        }       
    }
       
    printf("\n");  

    // exit with main returning 0.
    return 0;

}
