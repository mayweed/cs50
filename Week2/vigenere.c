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

         //remettre y à 0 si fin de la chaine pas atteint
     // Sauter les caractères non alphabétiques
     //if( y == m && y < n)
     //if (m < n && n >= m)
     //    continue;
     //else
     //    break;
    // Attention: quand on est arrivé au bout du keyword, il faut
    // reprendre au début de ce même keyword pour encrypter!!
    // et on n'encrypte que des caractères, il faut donc passer si ce
    // n'est pas un caractères
    //
    // Tant que l'on n'est pas arrive au bout de n
    // Continuer à boucler sur m 
    // si isalpha alors encrypt isalpha
    // sinon simplement imprimer le caractère

    // Ne pas oublier la définition de key...
    // on remplit un tableau de longueur N avec la position
    // des lettres du mot clé
    // TODO: buggy compte aussi les espaces!!! Est ce vraiment
    // important??
    // Correler ça à s[i]
    int key[n];
    int position[n];
    printf("N egal: %i\n",n);
    int x=0;
    while (x < n) {
    for (int y = 0; y < m; y++) {
        key[y]=find_key(p[y]);
        printf("Key[%i]:%i\n",y,key[y]);
        }
    x+=1;
    }

    for (int i = 0; i < n; i++) {
     if (isalpha(s[i])){
        if (islower(s[i])) {
            found_letter=find_letter_min(s[i]);
            position[i]=found_letter;
            int cipher=(position[i] + key[i]) % 26;
            printf("Cipher,position,key: %i %i %i\n",cipher,position[i],key[i]);
        for (int i = 0; i < 25; i++) {
            if (i == cipher && found_letter != 0)
                printf("%c", alphabet[i]);
            }
        }

        else if (isupper(s[i])) {
            found_letter=find_letter_maj(s[i]);
            position[i]=found_letter_maj;
            int cipher=(position[i] + key[i]) % 26;
            printf("Cipher,position,key: %i %i %i\n",cipher,position[i],key[i]);
        for (int i = 0; i < 25; i++) {
            if (i == cipher && found_letter_maj != 0)
                printf("%c", AlphaBetMaj[i]);
            }
          }
        }
     else { 
         printf("%c",s[i]);
     }
    }
    printf("\n");
}
