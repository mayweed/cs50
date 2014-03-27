#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>


int main(int argc, string argv[])
{
    //string key = argv[1];
    //int key = atoi(argv[1]); 

    char alphabet[26];
    int i=1;
    for(int a='a';a<='z';a++) {
       alphabet[i]=a;
       //Testing purpose
       //printf("Prems lettre:%i %c\n",i,alphabet[i]);   
       i+=1;
       }

    char AlphaBetMaj[26];
    int y=1;
    for(int a='A';a<='Z';a++) {
       AlphaBetMaj[y]=a;
       //Testing purpose
       //printf("Prems lettre:%i %c\n",y,AlphaBetMaj[y]);   
       y+=1;
       }

    //printf("Please give me a sentence to encrypt:");
    //string a = GetString();
    
    // Need to factor out the encrypt function
    // Input: the given letter / Output: the encrypted given letter
    // Testing purpose
    printf("Lettre:");
    char a=GetChar();
    int found_letter=0;
    for (int i = 1; i < 26; i++) {
        if (alphabet[i]==a){
            printf("trouvé %i\n",i);
            found_letter=i;
        }
    }
    
    int found_letter_maj=0;
    for (int y = 1; y < 26; y++) {
        if (AlphaBetMaj[y]==a){
                printf("trouvé %i\n",y);
                found_letter_maj=y;
        }
    }

    //Testing purpose
    printf("Key:");
    int key=GetInt();
    int cipher=(found_letter+key) % 26;
    int cipher_maj=(found_letter_maj+key) % 26;
    
    //Need to rework on that so that when it's uppercase
    //only the uppercase is displayed and vice-versa
    for (int i = 1; i < 26; i++) {
        if (i == cipher && found_letter !=0)
            printf("Encrypt: %c\n", alphabet[i]);
        else if ( i == cipher_maj && found_letter_maj != 0)
            printf("Encrypt: %c\n", AlphaBetMaj[i]);
    }
}
