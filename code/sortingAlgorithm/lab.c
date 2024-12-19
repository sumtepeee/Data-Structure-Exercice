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

int main(int argc, char const *argv[])
{
    char string[] = "algorithm";  
    printf("Sıralanacak olan dizimiz \t %s\n",string);

    bubbleSort(string);
    printf("after bubbleSort \t %s\n",string);

    selectionSort(string);
    printf("after selectionSort \t %s\n",string);

    insertionSort(string);
    printf("after insertion \t %s\n",string);



    return 0;
}
