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

int main(void)
{
    printf("Number:");
    long long int s= GetLongLong();
    card_numbers[card_number_length]=arrayize(s);
    int sum_uneven=0;
    int sum_even=0;

    for (int i=0; i < card_number_length; i++){
       if (i%2==0)
          sum_even+=card_numbers[i];
       else if (i%2!=0)
          sum_uneven+=(card_numbers[i] * 2);

    //Testing purpose
    printf("Sum Uneven %i\n",sum_uneven);
    printf("Sum Even %i\n",sum_even);
    printf("\n");
    }
        //printf("Test uneven: Number[%i]:%lli\n",i,card_numbers[i]); 
    printf("Sum Uneven %i\n",sum_uneven);
    printf("Sum Even %i\n",sum_even);
    printf("Total Sum %i\n",sum_uneven + sum_even);
         
}

