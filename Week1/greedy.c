//gcc greedy.c -lcs50 -Wall -lm
#include<stdio.h>
#include<math.h>
#include<cs50.h>

int convert (int change)
{
    int quarter,dime,nickel,penny=0;
    while (change > 0){
        while(change > 25){
	    change -= 25;
	    quarter += 1; 
        break;
	}
	while (change > 10 && change < 25){
	    change -= 10;
        dime +=1;
        break;
	}
	while (change > 5 && change < 10){
	    change -= 5;
	    nickel +=1;
        break;
	}
	while (change < 5 && change > 0){
        change -=1;
        penny+=1;
        break;
	}
    }
        printf ("Number of coins=%d\n",quarter+dime+nickel+penny);
}

int main(void)
{
    printf("O hai!  How much change is owed?\n");
    float sum=GetFloat();
    int change=round(sum*100);
    printf("Change due:%i\n",change);
    convert(change);
}

