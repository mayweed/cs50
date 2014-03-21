#include<stdio.h>
#include<string.h>
#include<cs50.h>

int main(void)
{
    printf("Number:");
    long long int s= GetLongLong();
    long long int card_numbers[MAX_CARD];

    for (int i=0; i < MAX_CARD; i++) {
    while (s > 0){
        card_numbers[i]=s%10;
        printf("Number[%i]:%lli\n",i,card_numbers[i]);
        s/=10;
    }
    }


}
