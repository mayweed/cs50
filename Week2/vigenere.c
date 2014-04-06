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
        printf ("You must pass one and only one argument\n");
        return 1;
    }
        
    string p = argv[1];
    int m = 0;
    for (int i=0; i < strlen(p); i++){
        if (!isalpha(p[i])){
            printf("Non-alphabetical input detected!!\n");
            return 1;
        }
    }

    printf("String to encrypt:");
    string s=GetString();
    int n = strlen(s);

    // Une partie pour remplir un tableau ==n des lettres du keyword
    int key[n];
    for (int x = 0; x < n; x++){ 
            key[x]=find_key(p[m]);
            //Testing purpose
            //printf("Key[%i]:%i\n",x,key[x]);
            m+=1;
        if (p[m]=='\0'){
            m=0;
        }
    }

    //parcourir la chaine mettre en tableau les positions des lettres
    int position[n];
    for (int y= 0; y < n; y++) {
        if (!isalpha (s[y])){
            continue;
        }
        else if (islower(s[y])) { 
            position[y]= find_letter_min(s[y]);
        }   
        else if (isupper(s[y])) { 
            position[y]=find_letter_maj(s[y]);
        }
    //    printf("Position[%i]:%i\n",y,position[y]);
    }

    int w=0;
    for (int z=0; z < n; z++){
        if(isalpha(s[z])){
            if(islower(s[z])){
            int cipher=(position[z] + key[w]) % 26;
            // Testing purpose
            //printf("cipher,position[%i],key[%i]: %i %i %i\n",z,w,cipher,position[z],key[w]);
            w+=1;
            for (int i = 0; i <= 25; i++) {
                if (i == cipher && found_letter)
                    printf("%c", alphabet[i]);
                    }
            }
            else if (isupper(s[z])){
                int cipher=(position[z] + key[w]) % 26;
                // Testing purpose
                //printf("cipher,position[%i],key[%i]: %i %i %i\n",z,w,cipher,position[z],key[w]);
                w+=1;
                for (int i = 0; i <= 25; i++) {
                    if (i == cipher && found_letter_maj)
                        printf("%c", AlphaBetMaj[i]);
                        }
            }
        }
        else
            printf("%c",s[z]);
        }
    printf("\n");
}
