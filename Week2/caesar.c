#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>

    
char AlphaBetMaj[26];
char alphabet[26]; 
int found_letter = 0;
int found_letter_maj = 0;
int cipher=0;
int cipher_maj=0;

// Cette fonction prend une lettre et retourne la position de la
// lettre dans l'alphabet
int find_letter_min(char letter)
{
    int i=1;

    for(int a='a';a<='z';a++) {
        alphabet[i]=a;
        i+=1;
    }

    for ( i = 1; i <= 26; i++) {
       if (alphabet[i]==letter) {
          found_letter=i;
       }
    }
    return found_letter;
}

// id mais pour les majuscules
int find_letter_maj(char letter)
{
    int y=1;

    for(int a='A';a<='Z';a++) {
        AlphaBetMaj[y]=a;
        y+=1;
    }
    
    for ( y = 1; y <= 26; y++) {
       if (AlphaBetMaj[y]==letter) {
          found_letter_maj=y;
       }
    } 
    return found_letter_maj;
}

// Prend en argument cipher, parcourt les tableaux et renvoie le
// caractère encrypté
char encrypt(int cipher)
{
    for (int i = 1; i < 26; i++) {
        if (i == cipher && found_letter !=0){
           printf("%c", alphabet[i]);
           }
        else if ( i == cipher && found_letter_maj !=0) {
           printf("%c", AlphaBetMaj[i]);
           }
    } 
    return 0;
}

int main(int argc, string argv[])
{
    if(argc > 2 || argc < 2 ) {
        printf("Argc:%d\n",argc);
        printf ("You must pass one and only one argument\n");
        return 1;
    }

    printf("Please give me a string:");
    string p = GetString();
    long int key= strtol(argv[1], NULL,10);

    for (int i = 0, n = strlen(p); i < n; i++) {
        if (islower(p[i])) {
            find_letter_min(p[i]);
            int cipher=(found_letter + key) % 26;
            encrypt(cipher);
        }
        else if (isupper(p[i])) {
            find_letter_maj(p[i]);
            int cipher_maj=(found_letter_maj + key) % 26;
            encrypt(cipher_maj);
        }   
        else printf("%c",p[i]);

    }
    printf("\n");
}
