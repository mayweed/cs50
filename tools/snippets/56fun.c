#include<stdio.h>

//Write a prog, each 56 print the number
//Use for calculating the number of record
//to be changed by a certain person (each one
//gets 56 records). We got 392 records
int main(void)
{
        int i=1;
        int compteur=0;

        for (i=1;i <= 392; i++){
            compteur +=1;
        if (compteur == 56){
            printf("%d\n",i);
            compteur=0;
            }
        }

        return 0;
}
