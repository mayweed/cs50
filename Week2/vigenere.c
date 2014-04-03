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

    // TODO: buggy compte aussi les espaces!!! Est ce vraiment
    // important??
    // Correler ça à s[i]
    int key[n];
    int x=0;
    while (x < n) {
    for (int y = 0; y < m; y++){ 
            key[y]=find_key(p[y]);
            printf("Key[%i]:%i\n",y,key[y]);
    }
    x+=1;
    }

    int position[n];

    for (int i= 0; i < n; i++) {
     for (int y = 0; y < m; y++){ 
        if (!isalpha (s[i])){
            printf("%c",s[i]);
        }
        else if (islower(s[i])) { 
            position[i]= find_letter_min(s[i]);
            key[y]=find_key(p[y]);
            int cipher=(position[i] + key[y]) % 26;
            printf("i,y,cipher,found letter,key:%i %i %i %i %i\n",i,y,cipher,position[i],key[y]);
            for (int i = 0; i < 25; i++) {
                if (i == cipher && found_letter != 0)
                    printf("%c", alphabet[i]);
                    }
        }   
        else if (isupper(s[i])) { 
            position[i]=find_letter_maj(s[i]);
            key[y]=find_key(p[y]);
            int cipher=(position[i] + key[y]) % 26;
            printf("i,y,cipher,found letter,key: %i %i %i %i %i\n",i,y,cipher,position[i],key[y]);
            for (int i = 0; i < 25; i++) {
               if (i == cipher && found_letter_maj != 0)
                printf("%c", AlphaBetMaj[i]);
                }
            }
        }
    printf("\n");
    }
}
