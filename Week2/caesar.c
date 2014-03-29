#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<cs50.h>

    
int main(int argc, string argv[])
{

    //DOES NOT WORk!!!
    //DONT KNOW WHY!!!
    //long int key=0;
    
    if(argc > 2 || argc < 2 ) {
        printf("Argc:%d\n",argc);
        printf ("You must pass one and only one argument\n");
        return 1;
    }
    // Testing purpose!! Check Key Value
    // in fact, w/o this, it does not work, it segfault???
    //else {
        //long int key= strtol(argv[1], NULL,10);
      //  key= strtol(argv[1],NULL,10);
        //printf("Key:%li\n",key); 
        //}

    // Char Input
    printf("Letter:");
    char my_letter=GetChar();

    // Initialisation  et recherche des alphabets
    // Variables
    char AlphaBetMaj[26];
    int found_letter_maj=0;
    char alphabet[26]; 
    int found_letter=0;

    // Traiement
    if (islower(my_letter)){
        int i=1;

        for(int a='a';a<='z';a++) {
            alphabet[i]=a;
            //Testing purpose
            printf("Prems lettre:%i %c\n",i,alphabet[i]);   
            i+=1;
            }

        for ( i = 1; i <= 26; i++) {
        if (alphabet[i]==my_letter){
            printf("trouve minuscule %i\n",i);
            found_letter=i;
        }
        }
    }

    else if (isupper(my_letter)) {
        int y=1;

        for(int a='A';a<='Z';a++) {
            AlphaBetMaj[y]=a;
            //Testing purpose
            printf("Prems lettre:%i %c\n",y,AlphaBetMaj[y]);   
            y+=1;
            }
    
        for ( y = 1; y <= 26; y++) {
        if (AlphaBetMaj[y]==my_letter){
            printf("trouvé majuscule %i\n",y);
            found_letter_maj=y;
        }
        } 
    }

    // Yesterday at midnight it works?
    // Need to factor this out!!!
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
