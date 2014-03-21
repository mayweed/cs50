#include<stdio.h>
#include<string.h>
#include<cs50.h>

#define MAX_CARD 16

int card_number_length;
long long int card_numbers[MAX_CARD];

long long int arrayize(long long int s)
{
    int i = 0;
    while (s > 0){
        card_numbers[i]=s%10;
        printf("Number[%d]:%lli\n",i,card_numbers[i]);
        s/=10;
        i+=1;
        }
        // First try at fixing that fuc*** length prob
        card_number_length=i;
    return card_numbers[card_number_length];
}

long long int filter_uneven(long long int card_numbers[card_number_length])
{
     for (int i=0; i < card_number_length; i++){
         //let's ignore even nummber
         if (i%2 ==0)
             continue;
         printf("Test uneven: Number[%i]:%lli\n",i,card_numbers[i]); 
     }
     return 0;
}


int main(void)
{
    printf("Number:");
    long long int s= GetLongLong();
    //Ten, to test. Need to fix that length problem...
    card_numbers[card_number_length]=arrayize(s);
    // As a good boy, I listen to compiler and add &. Dont really get 
    // where my long long* parameter is...
    filter_uneven(&card_numbers[card_number_length]);
}

