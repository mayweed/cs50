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
// Reecrire une seule fonction avec if/else if et islower() isupper()
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

//prend un string et retourne un tableau avec les clés positionnelles
//des lettres
int find_key(char p)
{
    int key=0;
    if (islower(p)){
        find_letter_min(p);
        key=found_letter;
        //printf("Key min:%d\n",key);
        }
    else if (isupper(p)){
            find_letter_maj(p);
            key=found_letter_maj;
         //   printf("Key maj:%d\n",key);

        }
    return key;
}

int main(int argc, string argv[])
{
    if(argc > 2 || argc < 2 ) {
        printf("Argc:%d\n",argc);
        printf ("You must pass one and only one argument\n");
        return 1;
    }

    string p = argv[1];
    int m = strlen(p);

    printf("String to encrypt:");
    string s=GetString();
    int n = strlen(s);

    int key[m];
    for (int y = 0; y < m; y++){ 
            key[y]=find_key(p[y]);
            //printf("Key:%i\n",key[y]);
    }

    int position[n];
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            found_letter=find_letter_min(s[i]);
            position[i]=found_letter;
            //printf("Position:%i\n",position[i]);
        }
        else if (isupper(s[i])) {
            found_letter=find_letter_maj(s[i]);
            position[i]=found_letter_maj;
            //printf("Position:%i\n",position[i]);
        }
        else
            printf("%c",s[i]);
        }

        for ( int i = 0; i < n; i++) {
            int cipher=(position[i] + key[i]) % 26;
            //printf("cipher /found_letter/ key: %i %i %i\n",cipher,position[i],key[i]);
            for (int i = 0; i < 25; i++) {
                if (i == cipher && found_letter != 0)
                    printf("%c", alphabet[i]);
                else if (i == cipher && found_letter_maj != 0)
                    printf("%c", AlphaBetMaj[i]);

               }
        }
        printf("\n");
    
}
