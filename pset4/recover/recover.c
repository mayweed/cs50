/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include<cs50.h>
#include<stdio.h>

int main(int argc, char* argv[])
{
    // Open the card
    FILE* card = fopen("card.raw", "r");

    //char* sig="0xff 0xd8 0xff";
    int count=0;
    int sig=0;

    while (!feof(card))
    {
        //open a test file, which must be diff (todo)
        FILE* fptr= fopen("test.jpg","w");

        //read a block, should i use fread here?
        int block=fgetc(card);

        if (block==0xff){
            int second_block=fgetc(card);

            if (second_block==0xd8){
                fwrite(&block,8,1,fptr);
                int third_block=fgetc(card);

                if (third_block==0xff){
                    fwrite(&second_block,8,1,fptr);
                    fwrite(&third_block,8,1,fptr);
                    eprintf("AM IN THE THIRD BLOCK\n");

                    //STH is wrong here...
                    while (block!= 0xff){
                        int block2=fgetc(card);
                        fwrite(&block2,8,1,fptr);
                    }

                }
            }
            sig+=1;
        }
        count+=1;
        fclose(fptr);
    }
    //"you should ultimately find that the image contains 50 JPEGs."
    //printf("%d\n",sig);

    //should close the file and freed up mem
    fclose(card);
}
