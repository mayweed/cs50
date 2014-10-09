//enter a arg in mile, send back the same value in km
//./km_mile mile
#include<stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
double mile=atoi(argv[1]);

printf("%f miles == %f kilometers\n",mile,mile*1.609344);

}
