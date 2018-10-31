#include<stdio.h>
#include<string.h>
#include<cs50.h>

#define MAX_CARD 16

int card_number_length;
long long int card_numbers[MAX_CARD];

int add_number(int s)
{
    int sum=0;
    while (s > 0)
    {
        sum+=s%10;
        s/=10;
    }
    return sum;
}

int check_card(int x, int y)
{
    int sum= x+y;
    int first_number=card_numbers[card_number_length-1];

    // TODO:add some test for the second number
    if (((sum%10) == 0) && (first_number==3))
        printf("AMEX\n");
    else if (((sum%10) == 0) && (first_number==4))
        printf("VISA\n");
    else if (((sum%10) == 0) && (first_number==5))
        printf("MASTERCARD\n");
    else
        printf("INVALID\n");
    return 0;
}


long long int arrayize(long long int s)
{
    int i = 0;
    while (s > 0) 
    {
        card_numbers[i]=s%10;
        s/=10;
        i+=1;
    }


    if((i < 13) || (i > 16)) 
    {
        printf("INVALID\n");
        return 0;
    }
    else 
    {
        card_number_length=i;
        return card_numbers[card_number_length];
    }
}

int main(void)
{
    printf("Number: ");

    // Test number: 5673598276138003
    // should be invalid
    // got a runtime error ll > 16
    long long int s= get_long_long();
    
    card_numbers[card_number_length]=arrayize(s);
    int uneven_array[card_number_length];
    int sum_uneven=0;
    int sum_even=0;

    for (int i=0; i < card_number_length; i++) 
    {
       if (i%2==0)
          sum_even+=card_numbers[i];
       else if (i%2!=0)
       {
          uneven_array[i]=(card_numbers[i] * 2);
          sum_uneven+=add_number(uneven_array[i]);
        }
    }
    check_card(sum_uneven,sum_even);
}
