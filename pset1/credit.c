#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<math.h>

int add_number(int s) 
{
    int sum=0;
    while (s > 0){
        sum+=s%10;
        s/=10;
    }
    return sum;
}

int main(void)
{
    printf("Number:");
    // Test number: 5673598276138003
    // Tex ex 378282246310005
    long long int s= get_long_long();

    //math found on stackoverflow, very nice!!
    int index = floor(log10(llabs(s))) + 1;

    //should pass it as a pointer in a func?
    int card_num[index];
    for (int i=index-1;i>=0;i--){
        card_num[i]=s%10;
        s/=10;
    }

    //first: take the second to last index then -2 on this index
    int second_to_last_index=index-2;
    //eprintf("index %d,second to last == %d\n",index,card_num[second_to_last_index]);
    int num_to_sum=0;
    int sum=0;
    for (int i= second_to_last_index; i>=0;i-=2){
        num_to_sum =card_num[i]*2;
        sum+=add_number(num_to_sum);
        //eprintf("index:%d; num: %d, sum: %d \n \n",i,card_num[i],sum);
    }
    //eprintf("SECOND SUM \n \n");

    //second sum
    int last_index=index-1;
    for (int i= last_index; i>=0;i-=2){
        sum+=card_num[i];
        //eprintf("index:%d; num: %d, sum: %d \n",last_index,card_num[last_index],sum);
    }

    //final check
    if((index < 13) || (index > 16) || (sum%10 != 0)) {
            printf("INVALID\n");
    }
    else{
        if (card_num[0]== 3 && (card_num[1]==4 || card_num[1]==7)){
            printf("AMEX\n");
        }else if (card_num[0]==5 && (card_num[1]==1 || card_num[1]==2 || card_num[1]==3 || card_num[1]==4 || card_num[1]==5)){
            printf("MASTERCARD\n");
        }else if (card_num[0]==4){
            printf("VISA\n");
        }else{
            printf("INVALID\n");
        }
    }
        return 0;
}
