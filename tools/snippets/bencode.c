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

//not good use a pointer or sth...Know buffer overflow??
// Need to find the number of elts BEFORE so that I could
// use a pointer to metainfo with a malloc: a loop with
// fread + size as a counter?
char metainfo[1002];
size_t len = fread(metainfo, 1, 1000, p);
metainfo[len] = '\0';
printf("%s\n", metainfo);


fclose(p);

return 0;     
}
