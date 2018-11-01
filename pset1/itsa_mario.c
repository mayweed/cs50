#include <stdio.h>
#include <cs50.h>

int pyramide (int height)
{
    int i, j, k,whitespace,sharp;
    whitespace=height -1;
    sharp=1;
    
    for (i=0; i < height; i++) {
           for (j=0; j < whitespace; j++)
                   printf (" ");
           for (j=0; j < sharp; j++)
                   printf ("#");
           for (k=0; k < 2; k++)
                   printf(" ");
           for (j=0; j < sharp; j++)
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
    int height=GetInt();

    while ((height < 0 ) || (height > 23)) {
        printf("Height:");
        //if it's not an int GetInt() will prompt a retry...
        height=GetInt();
    }

    pyramide (height);
    return 0;
}
