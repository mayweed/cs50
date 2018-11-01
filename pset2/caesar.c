#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>

    
char AlphaBetMaj[26];
char alphabet[26]; 
int found_letter = 0;
int found_letter_maj = 0;

//This function takes a small letter and yields back
//his position in the alphabet.
int find_letter_min(char letter)
{
    int i=0;

    for(int a='a';a<='z';a++) {
        alphabet[i]=a;
        i+=1;
    }

    for ( i = 0; i < 26; i++) {
       if (alphabet[i]==letter) 
          found_letter=i;
    }
    return found_letter;
}

// Same as above for capital letters
int find_letter_maj(char letter)
{
    int y=0;

    for(int a='A';a<='Z';a++) {
        AlphaBetMaj[y]=a;
        y+=1;
    }
    
    for ( y = 0; y < 26; y++) {
       if (AlphaBetMaj[y]==letter) 
          found_letter_maj=y;
    } 
    return found_letter_maj;
}

int main(int argc, string argv[])
{
    if(argc > 2 || argc < 2 ) {
        printf ("You must pass one and only one argument\n");
        return 1;
    }
    else if (!isdigit(*argv[1])){
        printf("Your key must be a number\n");
        return 1;
    }

    printf("Please give me a string:");
    string p = get_string();
    long int key= strtol(argv[1], NULL,10);

    printf("ciphertext: "); //this is lame, should use sprintf() instead
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (islower(p[i])) {
            find_letter_min(p[i]);
            int cipher=(found_letter + key) % 26;
            printf("%c", alphabet[cipher]);
        }
        else if (isupper(p[i])) {
            find_letter_maj(p[i]);
            int cipher_maj=(found_letter_maj + key) % 26;
            printf("%c", AlphaBetMaj[cipher_maj]);
        }   
        else printf("%c",p[i]);
    }
    printf("\n");
}
