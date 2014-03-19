//gcc greedy.c -lcs50 -Wall -lm
#include<stdio.h>
#include<math.h>
#include<cs50.h>

int convert (int change)
{
    int quarter=0;
    int remainder = change - 25;

    if (remainder > 25){
	    remainder -= 25;
	    quarter += 1; 
    }

    //else if (remainder > 10 && remainder < 25){
      // while (remainder > 10 && remainder < 25){
	   // remainder -= 10;
     //   dime +=1;
	//}
    //}
    //else if (remainder > 5 && remainder < 10){
      // while (remainder > 5 && remainder < 10){
	    //remainder -= 5;
	    //nickel +=1;
	//}
    //}
    //else if (remainder < 5 && remainder > 0){
    //   while (remainder < 5 && remainder > 1){
    //    change -=1;
    //    penny+=1;
	//}
    //}
       // printf ("Number of coins=%d\n",quarter+dime+nickel+penny);
    printf("Remainder => %i\n",remainder);
    printf("Quarter => %i\n",quarter);
}

int main(void)
{
    printf("O hai!  How much change is owed?\n");
    float sum=GetFloat();
    int change=round(sum*100);
    printf("Change due:%i\n",change);
    convert(change);
}

