#include <stdio.h>

int pyramide (int height)
{
    int i, j,whitespace,sharp;
    whitespace=height;
    sharp=1;
    
    for (i=0; i < height; i++)
        {
           for (j=0; j < whitespace; j++)
                   printf (" ");
           for (j=0; j < sharp; j++)
                   printf ("#");
           whitespace--;
           sharp +=1;
           printf ("\n");
        }
}

int main (void)
{
    int height;
    printf ("Enter a height please:");
    height=getchar();
    pyramide (height);
}

