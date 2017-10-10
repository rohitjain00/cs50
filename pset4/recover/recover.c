#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    //Open memory card
    FILE* infile = fopen("card.raw", "r");


    uint8_t buffer[512];

    int jpg = 0;

    int floodgate = 0;

    char* title = malloc((sizeof(int)*3 + sizeof(char)*3));

    FILE* img = fopen("000.jpg", "a");

    while(fread(&buffer, sizeof(buffer), 1, infile))
    {
    	if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]==0xe0 || buffer[3]==0xe1))
    	{
    		if(floodgate ==1)
    		{
    			fclose(img);
    			//Close current jpg
    			jpg++;

    			if(jpg<10)
    			{
    				sprintf(title, "00%d.jpg", jpg);
    			}
    			else
    			{
    				sprintf(title, "0%d.jpg", jpg);
    			}

    			//Opens new jpg file
    			img = fopen(title,"a");
    		}

    		floodgate = 1;
    	}


	    if(floodgate ==1)
	    {
	    	fwrite(&buffer, sizeof(buffer), 1, img);
	    }
    }


    free(title);
    fclose(img);
    fclose(infile);

}