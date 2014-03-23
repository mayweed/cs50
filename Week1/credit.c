#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<cs50.h>

#define MAX_CARD 16

int card_number_length;
long long int card_numbers[MAX_CARD];

int length(long long int s)
{
    int counter=0;
    while (s > 0){
        s/=10;
        counter += 1;
    }
    // Testing purpose
    //printf("Counter:%i\n", counter);
    return counter;
}
long long int arrayize(long long int s)
{
    int i = 0;
    while (s > 0){
        card_numbers[i]=s%10;
        // Make it less verbose for a while
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
    // Test number: 378282246310005
    long long int s= GetLongLong();

    // Rework on that later on... 
    //    float amount=0;
    //while (true) {
    //    if((amount=GetFloat()) < 0){
    //        printf("Retry and be positive please:");
    //        continue;
    //    } 
    //    else
    //        break;
    //}
    // if ( length(s) < 13 || length(s) > 16){
    //         printf("Number:");
    // }

    card_numbers[card_number_length]=arrayize(s);
    //card number length is a mistake here or not in fact...
    //int uneven_array[card_number_length];
    int sum_uneven=0;
    int sum_even=0;
    
    // we should add the Product digit NOT the product itself!!!
    // Here is my 'bug'
    for (int i=0; i < card_number_length; i++){
       if (i%2==0)
          sum_even+=card_numbers[i];
       else if ((i%2!=0)&& (isdigit(card_numbers[13])!=0)){
          sum_uneven+=(card_numbers[13] * 2);
          //uneven_array[i]=(card_numbers[i] * 2);
          //printf("Uneven[%i]:%d\n",i,uneven_array[i]);
//          printf("Sum uneven:%d\n",sum_uneven); 
       }

    //Testing purpose
    //printf("Sum Uneven %i\n",sum_uneven);
    //printf("Sum Even %i\n",sum_even);
    //printf("\n");
    }
    printf("Sum Uneven %i\n",sum_uneven);
    printf("Sum Even %i\n",sum_even);
    //printf("Total Sum %i\n",sum_uneven + sum_even);
}
