/**
 * hello.c
 *
 * Tjitske Lohstroh
 * 
 *
 * Builds a pyramid using the users input for height.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    // declaring varialbles
    int pyramid_height = 0;

    // ask user for height and check if its between 0 and 23
    printf ("Please give me a number between 0 and 23\n");

    do
    {
        printf("Height:");
        pyramid_height = GetInt();
    }
    while (pyramid_height < 0 || pyramid_height > 23);


    // pyramide height thus number of lines
    for (int line=0; line < pyramid_height; line++)
    {
        // print spaces
        for(int space=0; space < pyramid_height - line - 1; space++)
        {
            printf(" ");
        }
        
        // print hashes
        for(int hash=0; hash < line + 2; hash++)
        {
            printf("#");
        } 
        printf("\n");       
    }  
}
      




