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
    char card_blocks[BUFSIZE];

    for (int i=0; i < BUFSIZE; i++)
    {
        fread(&card,sizeof(char),1,card);
        printf("card_blocks[%i]=%x\n",i,card_blocks[i]);
    }

}
