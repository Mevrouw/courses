/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 * Tjitske Lohstoh
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    /*-----------------------
    //linear search:
    if (n < 1)
    {
        return false;
    }
    
    for(int i=0; i<n; i++)
    {
        if(value == values[i])
        {
            return true;
        }
    }
    return false;
    --------------------------*/

// binary search

    if (value < 1)
    {
        return false;
    }
    
    // find beginnig and end of the list
    int beginning = 0;
    int end = n - 1;

    while (end >= beginning)
    {
        // find the middle
        int middle = (beginning + end) / 2;
        // if value = middle -> return true
        if (values[middle] == value)
        {
            return true;
        }
        // if value < middle -> reset end of the list.
        else if (value < values[middle])
        {
            end = (middle - 1);
        }
        // if n < middle -> reset beginning of the list.
        else
        {
            beginning = (middle + 1);
        }
     }   
    return false; 
   
}

    

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm (I choose selection sort)
    // Iterate through the array.
    for (int i = 0; i < (n - 1); i++)
    {
        // Find the position of the smallest number in unsorted part of list.
        // Store it in the varialble "min".
        int min = i;
        for (int j = (i + 1); j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;    
            }
        }
        // if min is not i -> swap value of [min] with value [i]
        if (min != i)
        {
            int temp = values[i];
            values[i] = values[min];
            values[min] = temp;
        }
        
    }
    return;
    
}
