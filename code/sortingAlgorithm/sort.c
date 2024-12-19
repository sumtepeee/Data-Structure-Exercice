/*
 * sort.c
 *
 *  Created on: 29 march  2024
 *      Author: Sumeyye
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sort.h"

void bubbleSort(char *arr) {
    int lent = strlen(arr);
    char copy;
    int swap = 1;

    while (swap == 1)
    {
        swap = 0;
        for (int i = 0; i < lent-1; i++)
        { 
            if (arr[i] > arr[i+1])
            {
                copy = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = copy;
                swap = 1;
            }   
            
        }
    }
}

void selectionSort(char *arr) {
    int n = strlen(arr);
    int min_index,i,j;
    char temp;

    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1 ; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                temp = arr[j];
                arr[j] = arr[min_index];
                arr[min_index] = temp;
                
            }   
        }  
       
    } 
}

void insertionSort(char *arr) {
    int lent = strlen(arr);
    char temp;
    int i,j;

    for (i = 1; i < lent ; i++)
    {
        temp = arr[i];
        j = i-1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            

        }
        arr[j+1] = temp;
        
    }
}