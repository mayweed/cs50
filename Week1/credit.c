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

int add_number(int s)
{
    int sum=0;
    while (s > 0){
        sum+=s%10;
        s/=10;
    }
    return sum;
}

int check_card(int x, int y)
{
    int sum= x+y;

    if ((sum%10) == 0)
        printf("Carte Valide\n");
    else
        printf("INVALID\n");

    return 0;
}


long long int arrayize(long long int s)
{
    int i = 0;
    while (s > 0){
        card_numbers[i]=s%10;
        //Testing purpose 
        //printf("Number[%d]:%lli\n",i,card_numbers[i]);
        s/=10;
        i+=1;
        }
    card_number_length=i;
    return card_numbers[card_number_length];
}

int main(void)
{
    printf("Number:");
    // Test number: 378282246310005
    long long int s= GetLongLong();
    card_numbers[card_number_length]=arrayize(s);
    int uneven_array[card_number_length];
    int sum_uneven=0;
    int sum_even=0;

    for (int i=0; i < card_number_length; i++){
       if (i%2==0)
          sum_even+=card_numbers[i];
       else if (i%2!=0){
          uneven_array[i]=(card_numbers[i] * 2);
          // Testing purpose
          //printf("Uneven[%i]:%d\n",i,uneven_array[i]);
          sum_uneven+=add_number(uneven_array[i]);

       }
    }
    //Testing purpose
    printf("Sum Uneven %i\n",sum_uneven);
    printf("Sum Even %i\n",sum_even);
    printf("Total Sum %i\n",sum_uneven + sum_even);
    check_card(sum_uneven,sum_even);
}
