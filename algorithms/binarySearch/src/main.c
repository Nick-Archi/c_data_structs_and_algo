#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

int binarySearch(int arr[], int size, int number);

int main(int argc, char * argv[])
{
	int arr[SIZE] = {1, 3, 5, 8, 9};

	// TODO: figure out how to read more than 1 char
	printf("%d\n", binarySearch(arr, SIZE, 8));

	return 0;
}

int binarySearch(int arr[], int size, int number)
{
	printf("Searching for number: %d\n", number);
	int left = 0;
	int right = size;

	int rVal = 0;

	while(!rVal && (left < right))
	{
		int mid = ((right - left) / 2) + left;

		if(arr[mid] == number)
		{
			rVal = 1;
		}
		else if(number < arr[mid])
		{
			right = mid; 
		}
		else
		{
			left = mid + 1;
		}
	}

	return rVal;
}

