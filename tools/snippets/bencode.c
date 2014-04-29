// Fun to test
//
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
char* torrent;
torrent=argv[1];

FILE* p= fopen(torrent,"r");

if (ferror(p))
   printf("I/O error when reading");
else if (feof(p))
   printf("End of file reached successfully");


int c; // note: int, not char, required to handle EOF
while ((c = fgetc(p)) != EOF) { 
        putchar(c);
       }

fclose(p);

return 0;     
}
