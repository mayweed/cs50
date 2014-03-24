// A very simple decimal to binary converter
// Always useful...
#include<stdio.h>
#include<cs50.h>

#define MAX_BIN 256

int binary(int integer)
{
int remainder[MAX_BIN];
int i=0;

//calculus,works
while (integer > 0){
    remainder[i]=integer%2;
    // Testing purpose
    //printf("Element %i, Valeur %i\n",i,remainder[i]);
    integer/=2;
    i+=1;
}

//remise en ordre, le -1 est important pour le '\0'
while (i>0){
    printf("%i",remainder[i-1]);
    i-=1;
}

printf("\n");
return 0;
}

int main(void)
{
    printf("Decimal:");
    int decimal=GetInt();
    binary(decimal);
}

