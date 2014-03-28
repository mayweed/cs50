#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>


int main(int argc, string argv[])
{

    //DOES NOT WORk!!!
    //DONT KNOW WHY!!!
    //if(argc !=2) {
    //        printf ("You must pass one and only one argument\n");
    //        return 1;
    //}
    
  
    // Initialisation des alphabets
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

    // Char Input
    printf("Letter:");
    char my_letter=GetChar();
  
    // Recherche séquentielle dans les alphabets
    int found_letter=0;
    for ( i = 1; i < 26; i++) {
       if (alphabet[i]==my_letter){
           printf("trouve minuscule %i\n",i);
           found_letter=i;
        }
    }

    int found_letter_maj=0;
    for ( y = 1; y < 26; y++) {
        if (AlphaBetMaj[y]==my_letter){
            printf("trouvé majuscule %i\n",y);
            found_letter_maj=y;
        }
    }
    
    //long key=strtol (argv[1],NULL,10);
    //int key=atoi(argv[1]);
    // With ATOI, core dumped!!
    printf("Key:");
    int key=GetInt();

    int cipher=(found_letter + key) % 26;
    int cipher_maj=(found_letter_maj + key) % 26;
    
    //Need to rework on that so that when it's uppercase
    //only the uppercase is displayed and vice-versa
    for (int i = 1; i < 26; i++) {
        if (i == cipher && found_letter !=0){
            printf("Encrypt: %c\n", alphabet[i]);
            printf("Found letter:%i + %i = %i\n",found_letter,key,found_letter+key);
        }
        else if ( i == cipher_maj && found_letter_maj != 0) {
            printf("Encrypt: %c\n", AlphaBetMaj[i]);
            printf("Found letter maj: %d + %d = %d\n",found_letter_maj,key,found_letter_maj + key);
        }
    } 
}
