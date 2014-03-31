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
    int i=0;

    for(int a='a';a<='z';a++) {
        alphabet[i]=a;
        i+=1;
    }

    for ( i = 0; i <= 25; i++) {
       if (alphabet[i]==letter) {
          found_letter=i;
       }
    }
    return found_letter;
}

// id mais pour les majuscules
int find_letter_maj(char letter)
{
    int y=0;

    for(int a='A';a<='Z';a++) {
        AlphaBetMaj[y]=a;
        //printf("letter %c\n", AlphaBetMaj[y]);
        y+=1;
    }
    
    for ( y = 0; y <= 25; y++) {
       if (AlphaBetMaj[y]==letter) {
          found_letter_maj=y;
       }
    } 
    return found_letter_maj;
}

int main(int argc, string argv[])
{
    if(argc > 2 || argc < 2 ) {
        printf("Argc:%d\n",argc);
        printf ("You must pass one and only one argument\n");
        return 1;
    }

    string p = argv[1];
    printf("String key:%s\n",argv[1]);

    int key=0;
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (islower(p[i])){
        find_letter_min(p[i]);
        key=found_letter;
        printf("Key min:%d\n",key);
        }
        else if (isupper(p[i])){
            find_letter_maj(p[i]);
            key=found_letter_maj;
            printf("Key maj:%d\n",key);

        }
    }
}


    // Cette partie pour la chaine entree par l'utilisateur
    // test int key=13;
    //for (int i = 0, n = strlen(p); i < n; i++) {
    //    if (islower(p[i])) {
    //        find_letter_min(p[i]);
    //        int cipher=(found_letter + key) % 26;
    //        printf("strlen argv %i\n",n);
    //        for (int i = 1; i < 26; i++) {
    //            if (i == cipher && found_letter !=0)
    //                printf("%c", alphabet[i]);
    //            }
    //    }
    //    else if (isupper(p[i])) {
    //        find_letter_maj(p[i]);
    //        int cipher_maj=(found_letter_maj + key) % 26;
    //        for (int i = 1; i < 26; i++) {
    //            if (i == cipher_maj && found_letter_maj !=0)
    //                printf("%c", AlphaBetMaj[i]);
    //            }
    //    }   
    //    else printf("%c",p[i]);
    //}
    //printf("\n");
//}
