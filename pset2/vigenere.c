#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>

    
char AlphaBetMaj[26];
char alphabet[26]; 
int found_letter = 0;
int found_letter_maj = 0;

// This function takes a letter and yields back his
// postion in the alphabet
int find_letter_min(char letter) 
{
    int i=0;

    for(int a='a';a<='z';a++) {
        alphabet[i]=a;
        i+=1;
    }

    for ( i = 0; i <= 25; i++) {
       if (alphabet[i]==letter) 
          found_letter=i;
    }
    return found_letter;
}

// Same for capital letters
int find_letter_maj(char letter) 
{
    int y=0;

    for(int a='A';a<='Z';a++) {
        AlphaBetMaj[y]=a;
        y+=1;
    }
    
    for ( y = 0; y <= 25; y++) {
       if (AlphaBetMaj[y]==letter) 
          found_letter_maj=y;
    } 
    return found_letter_maj;
}

// Take a letter, yields its position
int find_key(char p) 
{
    int key=0;
    if (islower(p)) {
        find_letter_min(p);
        key=found_letter;
    }
    else if (isupper(p)) {
            find_letter_maj(p);
            key=found_letter_maj;
    }
    return key;
}

int main(int argc, string argv[])
{
    if(argc > 2 || argc < 2 ) {
        printf ("You must pass one and only one argument\n");
        return 1;
    }
        
    string p = argv[1];
    int m = 0;
    for (int i=0; i < strlen(p); i++) {
        if (!isalpha(p[i])) {
            printf("Non-alphabetical input detected!!\n");
            return 1;
        }
    }

    printf("plaintext: ");
    string s=get_string();
    int n = strlen(s);

    // Fill an array with the key, extract from the given keyword
    // thanks to find_key() 
    int key[n];
    for (int x = 0; x < n; x++) {
        key[x]=find_key(p[m]);
        m+=1;
        if (p[m]=='\0') 
            m=0;
    }

    // Fill an other array with the letter position in the string
    // to be encrypted
    int position[n];
    for (int y= 0; y < n; y++) {
        if (!isalpha (s[y])) 
            continue;
        else if (islower(s[y])) 
            position[y]= find_letter_min(s[y]);
        else if (isupper(s[y])) 
            position[y]=find_letter_maj(s[y]);
    }

    printf("ciphertext: ");
    // Compute the result with the 2 arrays
    int w=0;
    for (int z=0; z < n; z++) {
        if(isalpha(s[z])) {
            if(islower(s[z])) {
                int cipher=(position[z] + key[w]) % 26;
                w+=1;
                printf("%c", alphabet[cipher]);
            }
            else if (isupper(s[z])) {
                int cipher=(position[z] + key[w]) % 26;
                w+=1;
                printf("%c", AlphaBetMaj[cipher]);
            }
        }
        else
            printf("%c",s[z]);
        }
    printf("\n");
}
