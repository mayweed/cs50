/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Resize a BMP file
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    int multiplier= atoi(argv[1]);

    //Should ensure that n is in [1,100]
    if ((multiplier < 1) || (multiplier > 100)) 
    {
       printf("The multiplying number must be between 1 and 100 inclusive\n");
       return 1;
    } 

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        return 4;
    }

    // Backup old header
    BITMAPFILEHEADER new_bf=bf;
    BITMAPINFOHEADER new_bi=bi;

    //Before writing, must change header(and bfSize?)
    new_bi.biWidth= bi.biWidth * multiplier;
    new_bi.biHeight= bi.biHeight * multiplier;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding =  (4 - (new_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //WRONG: forgot the (eventual) padding!! Should I multiply by 3 for
    //bytes in biSizeImage?? And each line is padded right?
    int scanline_bytes= (new_bi.biWidth*sizeof(RGBTRIPLE))+ new_padding;

    new_bi.biSizeImage=scanline_bytes*abs(new_bi.biHeight);
    new_bf.bfSize= new_bi.biSizeImage + 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines 
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // To loop n times on each scanline
        for(int u = 0; u < multiplier; u++)
        {
            // iterate over pixels in infile's scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write n * RGB triple to outfile
                for (int l = 0; l < multiplier; l++)
                {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }
            // Padding at the end of each line
            // skip over padding  in infile if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back in outfile
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }

            //on each scanline but the last
            //"Also, if n=4 (for example) think about what happens after
            //you have written padding to the outfile the 4th time."
            //Thx to YeahIProgram for that (readditing.com)
            if (u < multiplier -1)
            {
            fseek(inptr,-(bi.biWidth*sizeof(RGBTRIPLE)+padding),SEEK_CUR);
            }
        }
    }
    
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
