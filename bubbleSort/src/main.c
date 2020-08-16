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

void swap(int * val1, int * val2)
{
	*val1 = *val1 + *val2;	
	*val2 = *val1 - *val2; 
	*val1 = *val1 - *val2; 
}

void printArray(int array[])
{
	printf("Array =>");
	for(int i = 0; i < SIZE; i++)
	{
		printf(" %d =>", array[i]);
	}
	printf(" {END}\n");
}
