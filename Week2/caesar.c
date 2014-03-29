#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<cs50.h>

    
int found_letter = 0;
int found_letter_maj = 0;
char AlphaBetMaj[26];
char alphabet[26]; 

// Cette fonction prend une lettre et retourne la position de la
// lettre dans l'alphabet
int find_letter_min(char letter)
{
    //char alphabet[26]; 
    //int found_letter=0;

    int i=1;

    for(int a='a';a<='z';a++) {
        alphabet[i]=a;
        //Testing purpose
        printf("Prems lettre:%i %c\n",i,alphabet[i]);   
        i+=1;
        }

    for ( i = 1; i <= 26; i++) {
       if (alphabet[i]==letter) {
           printf("trouve minuscule %i\n",i);
           found_letter=i;
       }
       }
    return found_letter;
}

// id mais pour les majuscules
int find_letter_maj(char letter)
{
    //char AlphaBetMaj[26];
    //int found_letter_maj=0;

    int y=1;

    for(int a='A';a<='Z';a++) {
        AlphaBetMaj[y]=a;
        //Testing purpose
        printf("Prems lettre:%i %c\n",y,AlphaBetMaj[y]);   
        y+=1;
        }
    
    for ( y = 1; y <= 26; y++) {
       if (AlphaBetMaj[y]==letter) {
           printf("trouvé majuscule %i\n",y);
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

    // Char Input
    printf("Letter:");
    char letter=GetChar();
    if (islower(letter)) {
        find_letter_min(letter);
        printf("Found_letter:%i\n",found_letter);
    }
    else if (isupper(letter)) {
            find_letter_maj(letter);
            printf("Found_letter_maj:%i\n",found_letter_maj);
    }
    else printf("%c",letter);
    //printf("Please give me a string");
    //string p = GetString()
    //for (int i = 0, n = strlen(p); i < n; i++) {
         //char my_letter= p[i]; // char ou int???
         //if (islower(my_letter)) find_letter_min(my_letter);
         // else if (isupper(my_letter)) find_letter_maj
        //x=find_letter(my_letter); ==> renvoie found_letter un int...
        //encrypt(found_letter|ici x| + key)
        //Encrypt renvoie la lettre crypté
        //printf("%c", p[i]);
    long int key= strtol(argv[1], NULL,10);
    
    int cipher=(found_letter + key) % 26;
    int cipher_maj=(found_letter_maj + key) % 26;
             
    for (int i = 1; i < 26; i++) {
        if (i == cipher && found_letter !=0){
           printf("Encrypt: %c\n", alphabet[i]);
           printf("Found letter:%i + %li = %li\n",found_letter,key,found_letter+key);
           }
        else if ( i == cipher_maj && found_letter_maj != 0) {
               printf("Encrypt: %c\n", AlphaBetMaj[i]);
               printf("Found letter maj: %d + %ld = %ld\n",found_letter_maj,key,found_letter_maj + key);
               }
        } 
}
