# ads
Algorithms and data structures
Queue - FIFO.
ChessSearch - finding the shortest way for a 
chess knight located on 8*8 board.


#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define dim 4

void PrintArray(int* array, int dimension)
{
	int i = 0;
	for (i = 0; i < dimension; i++)
		printf("%i ", array[i]);
	printf("\n");
}
int* Merge(int* leftArray, int* rightArray,int dimension)
{
	int left = 0, right = 0, result = 0;
	int* resultArray = (int*)malloc(sizeof(int)*dimension * 2);
	while ((left < dimension) && (right<dimension))
	{
		if (leftArray[left] > rightArray[right])
		{
			resultArray[result] = rightArray[right];
			result++;
			right++;
		}
		else
		{
			resultArray[result] = leftArray[left];
			result++;
			left++;
		}
	}
	if (left == dimension)
	{
		for (; right < dimension; right++)
		{
			resultArray[result] = rightArray[right];
			result++;
		}
	}
	if (right == dimension)
	{
		for (; left < dimension; left++)
		{
			resultArray[result] = rightArray[left];
			result++;
		}
	}
	return resultArray;
}

int* MergeSort(int* arr, int dimension)
{
	PrintArray(arr, dimension);
	if (dimension == 2)
	{
		int temp = 0;
		if (arr[0] > arr[1])
		{
			temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
		return arr;
	}
	else
	{
		int i = 0;
		int middle = dimension / 2;
		int* leftHalf = (int*)malloc(sizeof(int)*dim);
		int* rightHalf = (int*)malloc(sizeof(int)*dim);
		for (i = 0; i < middle; i++)
			leftHalf[i] = arr[i];
		for (; i < dimension; i++)
			rightHalf[i] = arr[i];
		leftHalf = MergeSort(leftHalf, middle);
		rightHalf = MergeSort(rightHalf, middle);
		arr = Merge(rightHalf, leftHalf,middle);
		return arr;
	}
}





int main()
{
	int i = 0;
	//int leftArray[dim] = { 1,3,5,8 };
	//int rightArray[dim] = { 4,6,7,9};
	//int* mergedUp = 0;
	//mergedUp = Merge(leftArray, rightArray, dim);
	//PrintArray(mergedUp, 2 * dim);
	
	int arrayUns[dim * 2] = { 8, 6, 5, 9, 1, 4, 3, 7 };
	int* sortArray = (int*)malloc(sizeof(int)*dim * 2);
	for (i = 0; i < dim; i++)
		sortArray[i] = arrayUns[i];
	for (; i < 2 * dim;i++)
		sortArray[i] = arrayUns[i];
	sortArray = MergeSort(sortArray, 2*dim);
	PrintArray(sortArray,2*dim);




	scanf("%i", &i);
}
