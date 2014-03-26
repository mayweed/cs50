#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>


//int main(int argc, string argv[])
int main (void)
{
    //TEST
    //initialiser un tableau alphabetique pour les minuscules via ascii
    char alphabet[26];
    //int key = atoi(argv[1]); 
    //Reessayer pour les majuscules avec une double boucle for...
    int i=1;
    for(int a='a';a<='z';a++) {
       alphabet[i]=a;
       printf("Prems lettre:%i %c\n",i,alphabet[i]);   
       i+=1;
       }

    //Boucle pour trouver la position d'une lettre.
    // Testing purpose
    printf("Une lettre:");
    char a = GetChar();
    int found_letter=0;
    for (int i = 1; i < 26; i++) {
        if (alphabet[i]==a){
            printf("trouvé %i\n",i);
            found_letter=i;
        }
    }
    //Testing purpose
    printf("Key:");
    int key=GetInt();
    int cipher=(found_letter+key) % 26;
    printf("cipher:%i\n", cipher); 

    for (int i = 1; i < 26; i++) {
        if (i == cipher)
            printf("Encrypt: %c\n", alphabet[i]);
    }
}
