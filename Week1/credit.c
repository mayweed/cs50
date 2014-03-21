#include<stdio.h>
#include<string.h>
#include<cs50.h>

#define MAX_CARD 16

//int measure_number(int number)
  //int sum=0;
  //for (i=0; i< MAX_CARD;i++)
   //   if (number%10);{
    //  sum+=1;
     // number=number/10;
    //  }
     // else
      //    printf("Sum:%i\n",sum);

  
   
int main(void)
{
    printf("Number:");
    long long int s= GetLongLong();
    long long int card_numbers[MAX_CARD];

    for (int i=0; i < MAX_CARD; i++)
    {
        card_numbers[i]=s%10;
        printf("Number:%lli\n",card_numbers[i]);
        s/=10;
        printf("S egal:%lli\n",s);
           
    }


}
