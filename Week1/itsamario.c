// Compile with: $ gcc itsamario.c -I/usr/local/include -L/usr/local/lib
// -lcs50 -o itsamario
//
#include <stdio.h>
#include <cs50.h>

int pyramide (int height)
{
    int i, j,whitespace,sharp;
    whitespace=height;
    sharp=1;
    
    for (i=0; i < height; i++)
        {
           for (j=0; j < whitespace; j++)
                   printf (" ");
           for (j=0; j <= sharp; j++)
                   printf ("#");
           whitespace--;
           sharp +=1;
           printf ("\n");
        }
}


int main (void)
{
    int height;
    while ((height < 0 ) || (height > 23))
    {
        printf("Height:");
        //if it's not an int GetInt() will prompt a retry...
        height=GetInt();
    }
    pyramide (height);
}
