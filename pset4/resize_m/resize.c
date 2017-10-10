/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    float factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

     if (factor > 100 || factor < 0 )
    {
        fprintf(stderr, "factor cannot be greater than 100 and less than 0");
        return 5;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
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

    //changing the New file accordingly

    // https://stackoverflow.com/questions/9127246/copy-struct-to-struct-in-c
    BITMAPFILEHEADER bf_out = bf;
    BITMAPINFOHEADER bi_out = bi;
    
    bi_out.biWidth *=factor;
    bi_out.biHeight *=factor;
    bf_out.bfSize = ((bf.bfSize-54)* factor)+54;

    // determine padding for scanlines
    int padding_out = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding = (4 - ((bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;

    //changing the absolute size of BMP
    bi_out.biSizeImage = ((bi_out.biWidth * sizeof(RGBTRIPLE) +padding) * abs(bi.biHeight));

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    int inptr_line = ((bi.biWidth * sizeof(RGBTRIPLE) ) + padding);

   // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //iterate over each scanline factor times
        for(int j = 0; j < factor; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int r = 0; r < factor; r++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            //then add it back (to demonstrate how)
            for (int k = 0; k < padding_out; k++)
            {
                fputc(0x00, outptr);
            }

            fseek(inptr, -inptr_line, SEEK_CUR);
        }

        fseek(inptr, inptr_line, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
