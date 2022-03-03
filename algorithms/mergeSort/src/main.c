#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* SIZE will not be 0-indexed */
#define SIZE 6

int globalCalls = 0;

void mergeSort(int input[], int left, int right, int output[]);
void merge(int input[], int left, int right, int mid, int output[]);
void printArray(int input[]);

int main(int argc, char * argv[])
{
	int input[SIZE] = {8, 7, 1, 5, 9, 2};	
	int * output = malloc(sizeof(int) * SIZE);

	printf("Before mergeSort\n");
	printArray(input);

	mergeSort(input, 0, SIZE-1, output);

	printf("After mergeSort\n");
	printArray(output);

	return 0;
}

/*
* @brief Perform a mergeSort algo
*
* @pre 
*
* @post output array will contain fully sorted input
*
* @description left and right will be 0 indexed
* 			   example) SIZE = 10, left = 0, right = 9
*/
void mergeSort(int input[], int left, int right, int output[])
{	
	if(right <= left)
	{
		return;
	}

	// calculate mid position
	int mid = (left + right)/2;

	// perform another mergeSort
	mergeSort(input, left, mid, output);
	mergeSort(input, mid+1, right, output);

	// when done, perform the merge
	merge(input, left, right, mid, output);
}

void merge(int input[], int left, int right, int mid, int output[])
{
	// copy left & mid positions
	int copyL = left;
	int copyR = mid+1;
	
	// copy current left position
	int curr = left;

	// loop through input to make comparisions
	while((copyL <= mid) && (copyR <= right))
	{
		// compare the input values
		if(input[copyL] < input[copyR])
		{
			output[curr] = input[copyL];
			copyL++;
		}
		else
		{
			output[curr] = input[copyR];
			copyR++;
		}

		curr++;
	}

	// determine which portion still has remaining values
	while(copyL <= mid)
	{
		output[curr] = input[copyL];
		copyL++;
		curr++;
	}

	while(copyR <= right)
	{
		output[curr] = input[copyR];
		copyR++;
		curr++;
	}

	// reflect the changes of output with the input
	int reflect = left;
	while(reflect <= right)
	{
		input[reflect] = output[reflect];
		reflect++;
	}
}

void printArray(int input[])
{
	printf("BEGIN: [");
	for(int i = 0; i < SIZE; i++)
	{
		printf(" %d ", input[i]);
	}
	printf("] :END\n");
}
