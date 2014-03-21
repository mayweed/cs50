#include<stdio.h>
#include<string.h>
#include<cs50.h>

int card_number_length;
long long int card_numbers[];

long long int arrayize(long long int s)
{
    int i = 0;
    while (s > 0){
        card_numbers[i]=s%10;
        //printf("Number[%d]:%lli\n",i,card_numbers[i]);
        s/=10;
        i+=1;
        }
        card_number_length=i;
        //printf("Test i: %i\n",i);
        return card_numbers[i];
}

long long int filter_uneven(long long int card_numbers[i])
{
     for (int i=1; i < MAX_CARD; i++){
         //let's ignore even nummber
         if (i%2 ==0)
             continue;
         printf("Test uneven: Number[%lli]:%lli\n",i,card_numbers[i]); 
     }
     return 0;
}


int main(void)
{
    printf("Number:");
    long long int s= GetLongLong();
    arrayize(s);
    printf("Test: %lld\n", card_numbers[2]);
    filter_uneven(card_numbers[]);
}

