#include<stdio.h>


int main(void)
{
    //TEST
    //initialiser un tableau alphabetique pour les minuscules via ascii
    char alphabet[26];

    //Reessayer pour les majuscules avec une double boucle for...
    int i=0;
    for(int a='a';a<='z';a++) {
       alphabet[i]=a;
       printf("Prems lettre:%i %c\n",i,alphabet[i]);   
       i+=1;
       }
}
