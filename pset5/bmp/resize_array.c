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

    //Should ensure thta n is in [1,100]
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
    new_bi.biSizeImage=new_bi.biWidth*bi.biSizeImage;
    new_bf.bfSize= new_bi.biSizeImage + 54;

    // Sanity check
    //printf("Old biWidth=%x\nNew biWidth=%x\n",bi.biWidth, new_bi.biWidth);
    //printf("Old biHeight=%x\nNew biHeight=%x\n",bi.biHeight, new_bi.biHeight);
    //printf("Old biSizeImage=%x\nNew biSizeImage=%x\n",bi.biSizeImage, new_bi.biSizeImage);
    //printf("Old bfSize=%x\nNew bfSize=%x\n",bf.bfSize, new_bf.bfSize);

    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    //int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // temporary storage
    RGBTRIPLE triple;
    RGBTRIPLE scanline[bi.biHeight][bi.biWidth];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
        // read RGB triple from infile
        fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
        scanline[i][j]=triple;

        // skip over padding, if any
        //fseek(inptr, padding, SEEK_CUR);
        fwrite(&scanline[i][j], sizeof(scanline[i][j]), 1, outptr);
        }
        // Initialize scanline array 
        //    for (int l = 0; l < multiplier; l++)
        //    {
        //         scanline[i] = triple;
        //    }

        // then add it back (to demonstrate how)
        //for (int k = 0; k < padding; k++)
        //{
        //    fputc(0x00, outptr);
        //}
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
