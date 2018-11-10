/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

//#include<cs50.h>
#include<stdio.h>
#include<stdbool.h>

int main(int argc, char* argv[])
{
    //Usage
    if (argc!=2){
        fprintf(stderr,"Usage: an arg is missing ./recover your card\n");
        return 1;
    }

    // Open the card
    FILE *card = fopen("card.raw", "r");
    if (card==NULL) return 2;

    //open the output file
    FILE *outptr=NULL;

    //not int coz int == 8 bytes!! We compare bytes per bytes
    //we want a 1-byte type
    unsigned char buffer[512];
    bool start=false;

    //https://www.tutorialspoint.com/cprogramming/c_scope_rules.htm
    int count=0;
    char filename[8];

    //Return value (ccpreference.com)
    //Number of objects read successfully, which may be less
    //than count if an error or end-of-file condition occurs.
    while (fread(buffer,512,1,card)==1)
    {
        //block aligned, check only the first bytes of the buffer (cf spec)
        //the last one: F0 == 1111 0000 while e == 1110 so if you & the two you
        //get a 'e' (as 1&0 = 0) and the 4 last bits always yields0, whatever the bits

        //check for sig in the first buffer blocks
        if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0){
               start=true;
        }
        else
            start=false;

        //I encountered a sig
        if (start){
            //one is underway
            if (outptr != NULL){
                fclose(outptr);
            }
            snprintf(filename,sizeof(filename),"%03d.jpg",count);
            outptr=fopen(filename,"w");
            fwrite(&buffer,512,1,outptr);
            count+=1;
        }else{
            //false start (first bytes are no good)
            if (outptr!=NULL)
                fwrite(&buffer,512,1,outptr);
        }
    }
    //"you should ultimately find that the image contains 50 JPEGs."
    //eprintf("%d\n",sig);

    //should close the file and freed up mem
    fclose(card);
}
