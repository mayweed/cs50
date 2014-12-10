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
    //FILE* test = fopen("test", "w");


    FILE* test.raw = fopen("test.raw","w");
    // In both cases with BUFSIZE it's segfault!!!But it did not with
    // the precise number of bytes??? With a define it
    // works...Strange...It segfaults with an array though...
    // BYTE card_blocks[CARDSIZE];//oops segfault...
    // 
    // OKI:should read 512 by 512 bytes
    BYTE* card_blocks=(BYTE*)malloc(sizeof(BYTE)*CARDSIZE);

//    char* sig="0xff 0xd8 0xff 0xe0";

    for(int i=0; i < CARDSIZE;i++)
    {
        fread(&card_blocks[i],sizeof(BYTE),1,card);

        if(card_blocks[i]==0xff && card_blocks[i+1]==0xd8 && card_blocks[i+2]==0xff 
                        && (card_blocks[i+3]==0xe0|| card_blocks[i+3]==0xe1))
        {
            fwrite(&card_blocks[i],sizeof(BYTE),1,test.raw);
            if(card_blocks[i]==0xff && card_blocks[i+1]==0xd8 && card_blocks[i+2]==0xff 
                        && (card_blocks[i+3]==0xe0|| card_blocks[i+3]==0xe1))
                    fclose(test.raw);
        }

    }

    //should close the file and freed up mem
    fclose(card);

    //fclose(test);

    free(card_blocks);
}
