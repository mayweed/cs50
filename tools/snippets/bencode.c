// Fun to test
// TODO:
// - Rassembler les informations dans une structure
// qui parse le torrent.
// - Ecrire des fonctions réutilisables (via un bencode.h)
// pour parser les réponses du tracker
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char* argv[])
{
    char* torrent;
    torrent=argv[1];

    FILE* p= fopen(torrent,"r");

    if (ferror(p))
        printf("I/O error when reading");
    else if (feof(p))
        printf("End of file reached successfully");

    // not good use a pointer or sth...Know buffer overflow??
    // Need to find the number of elts BEFORE so that I could
    // use a pointer to metainfo with a malloc: a loop with
    // fread + size as a counter?
    char metainfo[1002];
    //size_t len = fread(metainfo, 1, 1000, p);
    //metainfo[len] = '\0';
    //printf("%s\n", metainfo);
    //char c;
    int count=0;

    fgets(metainfo,100,p);
    for (int i=0; i < 100; i++)
         printf("%c", metainfo[i]);
    
    if (isdigit(*metainfo)){
       count= (int)metainfo;
       printf("%i\n",count);
    }

    for (int y=0; y < count;y++)
        printf("%c",metainfo[y]);

    fclose(p);

    return 0;     
}
