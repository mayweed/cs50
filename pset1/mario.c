#include <stdio.h>
#include <cs50.h>

int pyramide (int height) 
{
    int i, j,whitespace,sharp;
    whitespace=height -1;
    sharp=1;
    
    for (i=0; i < height; i++) {
           for (j=0; j < whitespace; j++)
                   printf (" ");
           for (j=0; j <= sharp; j++)
                   printf ("#");
           whitespace--;
           sharp +=1;
           printf ("\n");
        }
    return 0;
}


int main (void)
{
    printf("Height:");
    int height=get_int();

    while ((height < 0 ) || (height > 23)) {
        printf("Height:");
        height=get_int();
    }

    pyramide (height);
    return 0;
}
