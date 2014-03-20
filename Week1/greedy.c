//gcc greedy.c -lcs50 -Wall -lm
#include<stdio.h>
#include<math.h>
#include<cs50.h>

int convert (int change)
{
    int quarter=0;
    int dime=0;
    int nickel=0;
    int penny=0;

    while (change >= 25){
	    change -= 25;
	    quarter += 1; 
    }

    while (change <= 25 && change >= 10){
         change -=10;
         dime += 1;
    }

    while (change <= 10 && change >= 5){
         change -= 5;
         nickel += 1;
    }

    while (change <= 5 && change > 0){
         change -= 1;
         penny +=1;
    }
    printf("Quarter => %i\n",quarter);
    printf("Dime => %i\n",dime);
    printf("Nickel => %i\n",nickel);
    printf("Penny => %i\n",penny);
    printf ("Number of coins = %d\n",quarter+dime+nickel+penny);
    return 0;
}

int main(void)
{
    printf("O hai!  How much change is owed?\n");
    float amount=0;

    while (true) {
        if((amount=GetFloat()) < 0){
            printf("Retry and be positive please:");
            continue;
        } 
        else
            break;
    }
    int change=round(amount*100);
    convert(change);
    return 0;
}
