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

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    // Let's open the card
    FILE* card = fopen("card.raw", "r");

    BYTE card_blocks[sizeof(card)];

    while(feof(card) != 0)
        {
        fread(&card, sizeof(BYTE), card);
        //fwrite(
        }

}
