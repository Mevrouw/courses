/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 * Tjitske Lohstroh
 *
 * Recovers JPEGs from a forensic image.
 */
 
 // #include "bmp.h" // typedef BYTE is declared here!
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
 
 typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{

    // accept no commandline arguments
    if (argc != 1)
    {
        printf("This program accepts no commandline aguments\n");
        return 1;
    }
   
    
    // Open card file
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {   
        fclose(inptr);
        printf("Could not open file.\n" );
        return 3;
    }
    
          
    // buffer with 512 bytes
    BYTE buffer [512];
    
    // count how many jpegs recovered
    int jpgCounter = 0;
    
    // declare filenamecd
    char jpgTitle [8];
    
    // jpeg found?
    bool foundFirstJpg = false;
    
    // start jpeg?
    // bool jpgStart = false;
    
    // pointer to jpeg copy
    FILE* img = NULL;
    
    
    // Repeat until end of file:
    while (fread (&buffer, 512, 1, inptr) != 0)
    { 
        // Check if block of 512 bytes is the start of a new jpeg.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff 
        && (buffer[3] == 0xe0 || buffer[3] == 0xe1 ))
        {
            // if there's already an jpeg found, close current outfile
            if (foundFirstJpg == true)
            {
                fclose(img);
            }   
                
            foundFirstJpg = true; 
                
            // create a filename for img
            sprintf (jpgTitle, "%03d.jpg", jpgCounter);
                
            // open new jpeg-file 
            img = fopen (jpgTitle, "w");
            if (img == NULL)
            {
                printf("Could not open %s for writing", jpgTitle);
                return 4;
            }
            // and write buffer into it
            fwrite(&buffer, 512, 1, img);
                
            // count new jpeg
            jpgCounter++;
        }
            
        // if it is not the start of a new jpeg (& first jpeg is found)
        else if (foundFirstJpg == true)
        {
            // write into to current file 
            fwrite(&buffer, 512, 1, img);
        }   
          

    }
    // close last jpg after reaching end of file
    fclose(img);
    
    // close inptr file
    fclose(inptr);   
}     

