/**
 * initials.c
 *
 * Tjitske Lohstroh
 *
 * Prints initials
 */
 
#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    
    printf ("%c", toupper(name[0]));
    for(int i = 1, n=strlen(name); i < n; i++)
    {
        if (name[i] == 32)
        {  
            printf("%c",toupper(name[i + 1]));         
        }
    }
    printf("\n");
}
