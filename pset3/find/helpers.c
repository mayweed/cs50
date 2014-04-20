/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (value < 0)
       return false;

    for (int x=0; x < n; x++){
        if (values[x] == value){
            return true;
            break;
        }
        else if (values[x] != value)
           continue;
    }
    //by default false
    return false;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i=0; i < (n-1);i++){
        int element = values[i];
        printf("Values i[%d] %d\n",i, values[i]);
        for ( int j = 1; j < n; j++){
            printf("Values j [%d] %d\n", j,values[j]);
            if (values[i] > values[j]){
                values[i]=values[j];
                values[j]=element;
                printf("values (sorted?)[%d] %d\n",j,values[j]);
            }
            else break;
        }
    }
//    return values;
}
