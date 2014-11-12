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
#define CARDSIZE 14330368

typedef uint8_t BYTE;

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

    //Test
    FILE* test = fopen("test", "w");

    // In both cases with BUFSIZE it's segfault!!!But it did not with
    // the precise number of bytes??? With a define it
    // works...Strange...It segfaults with an array though...
    //BYTE card_blocks[14330369];//oops segfault...
    BYTE* card_blocks=(BYTE*)malloc(sizeof(BYTE)*CARDSIZE);

    for(int i=0; i < CARDSIZE;i++)
    {
        fread(&card_blocks[i],sizeof(BYTE),1,card);

        fwrite(&card_blocks[i],sizeof(BYTE),1,test);
    }

    //should close the file and freed up mem
    fclose(card);

    fclose(test);

    free(card_blocks);
}
