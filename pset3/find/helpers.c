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

int display(int values[], int size)
{
for (int i=0; i < size; i++)
    printf("%d\n",values[i]);
return 0;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Two steps: first the algo, then the sort the array passed
    // "destructively"
    // Two loops: one for walkthrough(j) one for steps and swap (i)
    for (int j=0; j < n-1; j++){
    for ( int i = 1; i < n ; i++){
        if (values[i-1] > values[i]){
            int element=values[i];
            values[i]=values[i-1];
            values[i-1]=element;
        }
      }
    }
//    display(values,n);
    //testing purpose, must find a way to change it "in place"
//    for (int i=0; i<n;i++)
 //       printf("%d\n",values[i]);
}


