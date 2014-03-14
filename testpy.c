#include <stdio.h>

int pyramide (int hauteur)
{
    int i, j,blancs,stars;
    blancs=hauteur;
    stars=1;
    
    for (i=0; i < hauteur; i++)
        {
           for (j=0; j<blancs; j++)
                   putchar (' ');
           for (j=0; j < stars; j++)
                   putchar ('*');
           blancs--;
           stars +=1;
           putchar ('\n');
        }
}

int main (void)
{
    pyramide (5);
}

