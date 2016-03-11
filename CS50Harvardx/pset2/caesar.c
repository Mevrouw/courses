/**
 * caesar.c
 *
 * Tjitske Lohstroh
 *
 * Accepts key from user in commandline and encrypts input.
 * c[i] = (p[i] + key) % 26
 */
 
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    // accept one command-line argument
    if (argc != 2)
    {
        printf("Please enter 1 key into commandline (Positive ints only!).\n");
        return 1;
    }
    
    // convert string argv[1] to an int.
    int key = atoi(argv[1]); 
    // Make sure the key is positive
    if (key < 1)
    {
        printf("Please enter 1 key into commandline (Positive ints only!).\n");
        // return a value of 1 (which tends to signify an error)
        return 1;
    }
    
    // prompt user for a string of plaintext
    // printf("Please type some text: \n");
    string p = GetString();

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // check if letter is alpha 
        if (isalpha (p[i]))
        {
            // if letter is also upper: rotate by "key" positions and print.
            if (isupper(p[i]))
            {
                // "A" = 65, so 65-65 = 0. 
                // After that you can add the key and apply modulo
                // Add 65 again to go back to the right letter :-)
                printf( "%c", (p[i] - 65 + key) % 26 + 65);
            }
            // rest must be alpha & lower case:)
            else 
            {
                // Rotate by "key" positions and print.
                // "a" = 97, so 97-97 = 0. 
                // After that you can add the key, apply modulo
                // Add 97 again to go back to the right letter :-)
                printf("%c", (p[i] - 97 + key) % 26 + 97);
            }
        }
        // keeps non alphabetical unchanged
        else 
        {
            printf ("%c", p[i]);  
        }
    } 

    printf("\n");  

    // Exit, with main returning 0.
    return 0;

}
