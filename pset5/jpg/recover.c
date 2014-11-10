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

int file_length (FILE* fp)
{
    int size=0;

    while(!feof(fp))
    {
        fgetc(fp);
        size+=1;
    }
    return size;
}

int main(int argc, char* argv[])
{
    // Let's open the card
    FILE* card = fopen("card.raw", "r");

    int BUFSIZE=file_length(card);

    //Is this necessary. Can i use directly card pointer instead?
    typedef uint8_t BYTE;
    BYTE *card_blocks=malloc(BUFSIZE);

    for (int i=0; i < BUFSIZE; i++)
    {
        fread(&card_blocks[i],sizeof(BYTE),1,card);
        printf("card_blocks[%i]=%x\n",i,card_blocks[i]);
    }

    //should close the file and freed up mem
    fclose(card);
}
