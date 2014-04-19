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
    for (int j=1; j < (n-1);j++){
        int element = values[j];
        //printf("Values i %d\n", values[i]);
      for ( int i = 0; i < n; i++){
          if (values[j] < values[i]){
              printf("values (i)[%d] %d\n",i,values[i]);
              values[j]=values[i];
              values[j-1]=element;
              printf("values (sorted?)[%d] %d\n",j,values[j]);
          }
          else if (values[i] < values[j]){
              i++;
              j++;
          }
      }
    }
//    return values;
}
