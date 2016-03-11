/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int needle, int haystack[], int size)
{
    // TODO: implement a searching algorith
    /*-------------------------------
    // Linear Search 
    if (size<1)
    {
        return false;
    }
    
    for(int i=0; i<size; i++)
    {
        if(haystack[i] == needle)   
        {
            return true;
        } 
    } 
    return false;
   -------------------------------------*/
   
   //Binairy Search
   
   if (needle<1)
    {
        return false;
    }
   

   //(look @ int begin to int end)
   int begin = 0; 
   int end = size-1;
   
   while (end >= begin)
   {
        //find middle value 
        int middleValue = (begin+end)/2;  
        //if middleValue = key return true
        if (haystack[middleValue] == needle)
        {
            return true;
        }
        //if middleValue is not key:
        //check wether the key is on the left or the right side:
        //if key is smaller than middleValue; int begin = values [0] int end = values [(n-1)-middleValue] 
        //in key is larger than middleValue; int begin = values[(n-1)-middleValue] end i= (n-1)
        else if (haystack[middleValue] > needle)
        {
            end = middleValue-1;
        }
        else
        {
            begin = middleValue+1;
        }
    }
return false; 
}

/**
 * Sorts array of n values.
 */
void sort(int haystack[], int size)
{
    // TODO: implement an O(n^2) sorting algorithm
    //iterate through all but the las number in the array
    //sart at the first value, index 0
    for (int i = 0; i< (size-1); i++)
    {
        //minIndex stores the index of the minimum item. 
        //j iterates over all the "unsorted" items.
        int minIndex = i;
        for (int j=(i+1);j < size;j++)
        {
            //find ande store the position of the smalest number
            if( haystack[j]< haystack[minIndex])
            {
                minIndex = j;
            }
        }
        
        //if value of smallest number is not the value of the index number:
        //swap the minimun value at the end of the sorted list
        //by using a temporary int to store the value of i during the swapping proces..
        if (minIndex != i)
        {
            int temp = haystack[i];
            haystack[i] = haystack [minIndex];
            haystack [minIndex] = temp;
        }
    }
    
    /*for (int i = 0; i < size; i++) 
        {
            printf("value [%d] = %d\n", i, haystack[i]);
        }
        */
    
    return;
    
   
}









