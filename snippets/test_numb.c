#include<stdio.h>

int add_number(int s)
{
    int sum=0;
    while (s > 0){
        sum+=s%10;
        s/=10;
    }
    printf("Sum egal:%i\n",sum);
    return sum;
}

int main(void)
{
    add_number(14);
}

