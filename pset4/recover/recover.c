/**
 * recover jpeg from a memory card raw file
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


int
main (int argc, char *argv[])
{
  // ensure proper usage
  if (argc != 2)
    {
      fprintf (stderr, "Usage: ./recover raw file\n");
      return 1;
    }

  // remember filenames
  char *memcard = argv[1];

  // open input file
  FILE *inFile = fopen (memcard, "r");
  if (inFile == NULL)
    {
      fprintf (stderr, "Could not open %s.\n", memcard);
      return 2;
    }
  int sizeOfABlock = 512;//byte
  int block[sizeOfABlock];
  //store number of files recovered
  int n = 0;
  char filename[8];
  int noOfBlocks = 0;

  //iterate over the whole inFile and break when recive EOF character
  while (true)
    {
      noOfBlocks++;

      fread (&block, sizeOfABlock, 1, inFile);

      //to check the exsistence of a JPEG starting
      //condition to be jpeg
      if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] > 0xe0 && block[3] < 0xef)
	{
	  printf ("Found a jpeg");

	  //open a new outfile with name according to the number it found
	  sprintf (filename, "%03i.jpg", n);
	  FILE *outfile = fopen (filename, "w");

	  if (outfile == NULL)
	    {
	      fprintf (stderr, "Could not open %s.\n", filename);
	      fclose (inFile);
	      return 3;
	    }

	  //wrtie the first block of the new jpeg
	  fwrite (&block, sizeOfABlock, 1, outfile);

	  //read and write from 2nd block until next jpeg starts
	  while (true)
	    {
	      fread (&block, sizeOfABlock, 1, inFile);

	      if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] > 0xe0 && block[3] < 0xef)
		{
		    //seek a block back
		  fseek (inFile, sizeOfABlock, SEEK_CUR);
		  break;
		}

	      fwrite (&block, sizeOfABlock, 1, outfile);
	    }
	  fclose (outfile);
	  //to change the filename each time
	  n++;
	}
      if (feof (inFile))
	{
	  break;
	}
    }
    fclose (inFile);
    printf ("Number of recovered jpeg %d\n", n);
    printf ("Number of blocks checked %d\n", noOfBlocks);
  // success
  return 0;
}
