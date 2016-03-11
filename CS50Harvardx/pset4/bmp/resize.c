/* resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Tjitske Lohstroh
 * Resizes 24-bit uncompressed BMPs by a factor of n.
 * Usage: ./resize n infile outfile
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // resize factor n
    int n = atoi(argv[1]);
    if (n < 0)
    {
        printf("n should be a positive int.\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    // construct BITMAPFILEHEADER for the outfile.
    BITMAPFILEHEADER bf_outfile;
    bf_outfile = bf;
    
    
    // construct BITMAPINFOHEADER for the outfile.
    BITMAPINFOHEADER bi_outfile;
    bi_outfile = bi;
    bi_outfile.biWidth = n * bi.biWidth;
    bi_outfile.biHeight = n * bi.biHeight;

    // determine padding for scanlines (in bytes)
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_outfile =  (4 - (bi_outfile.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;    
    
    // determine biSizeImage & bfSize for resized image. 
    // (abs because value can be negative)
    bi_outfile.biSizeImage = ((bi_outfile.biWidth * sizeof(RGBTRIPLE)) + padding_outfile) * abs(bi_outfile.biHeight);
    bf_outfile.bfSize = bi_outfile.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_outfile, sizeof(BITMAPFILEHEADER), 1, outptr);
     
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_outfile, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Resize vertically by writing scanline to outfile "n" times
        for(int m = 0; m < n; m++)
        {
            // iterate over pixels in scanline 
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // Resize horizontally by writing RGBtriple to outfile "n" times
                for (int k = 0; k < n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // Add padding to outfile.
            for (int k = 0; k < padding_outfile; k++)
            {
                fputc(0x00, outptr);
            }
        
            // Return to beginning of the scanline. (Current position minus width!)
            fseek(inptr, -(bi.biWidth * 3), SEEK_CUR);
        }
        
        // Goto beginning of the next scanline. (Current position + width and padding!)
        fseek(inptr, (bi.biWidth * 3) + padding, SEEK_CUR);
        
    
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
