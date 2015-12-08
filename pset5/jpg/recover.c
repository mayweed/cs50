/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define CARDSIZE 14330368
#define BLOCK 512

int file_length (FILE* fp)
{
    int size=0;

    while(!feof(fp))
    {
        fgetc(fp);
        size+=1;
    }
    //do not need '\0' count
    return size-1;
}


int main(int argc, char* argv[])
{
    // Let's open the card
    FILE* card = fopen("card.raw", "r");

    // Test
    FILE* test.raw = fopen("test.raw","w");

    // Array of 512 for a block 
    int card_blocks[BLOCK];

    //is this really necessary?
    //int counter=0;

    // Iterate through the card
    for(int i=0; i <= CARDSIZE;i++)
    {
        //Iterate through each block
        for(int y=0; y <= BLOCK; y++)
        {
        fread(&card_blocks[i],sizeof(int),1,card);

        if(card_blocks[i]==0xff && card_blocks[i+1]==0xd8 && card_blocks[i+2]==0xff 
                        && (card_blocks[i+3]==0xe0|| card_blocks[i+3]==0xe1))
            fwrite(&card_blocks[i],sizeof(int),1,test.raw);
        }
    //Should add a counter here, to the next 512 block
    //counter += 512;
    }

    //should close the file and freed up mem
    fclose(card);

    fclose(test);

    free(card_blocks);
}
