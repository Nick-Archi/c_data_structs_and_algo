#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 5

void bubbleSort(int * array);
void swap(int * val1, int * val2);
void printArray(int array[]);

int main(int argc, char * argv[])
{
	int unsorted[SIZE] = {8, 1, 5, 4, 0};
	printArray(unsorted);
	printf("\n");
	bubbleSort(unsorted);
	printArray(unsorted);
	return 0;
}

/*
* @brief bubble sort will initially start off as false, and then
* 		 assume that the array is sorted until it encounters an
*		 unsorted value
*	
* @post array will be sorted from least to greatest
*/
void bubbleSort(int * array)
{
	uint8_t sorted = 0;

	while(!sorted)
	{		
		sorted = 1;
		for(int i = 0; i < SIZE; i++)
		{
			if(array[i+1] < array[i])
			{
				sorted = 0;	
				swap(&array[i+1], &array[i]);
			}
		}
	}
}

/*
* @brief swap two interger values
*
* @post interger values have swapped positions
*/
void swap(int * val1, int * val2)
{
	*val1 = *val1 + *val2;	
	*val2 = *val1 - *val2; 
	*val1 = *val1 - *val2; 
}

/*
* @brief print the array of SIZE values
*
* @post array will be printed to standard out
*/
void printArray(int array[])
{
	printf("Array =>");
	for(int i = 0; i < SIZE; i++)
	{
		printf(" %d =>", array[i]);
	}
	printf(" {END}\n");
}
