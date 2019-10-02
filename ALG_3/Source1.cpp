#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#define dim 20
#define max 100+1



//int n = 10;
//int max = 10;
//int* inputArray = new int[n];
int inputArray[dim] = { 0 };




void CountingSort()
{
	int i = 0, j = 0;
	int additArray[max] = { 0 };
	for (i = 0; i < dim; i++)
		additArray[inputArray[i]]++;
	int pos = 0;
	for(i=0;i<max;i++)
		for (j = 0; j<additArray[i]; j++)
		{
			inputArray[pos] = i;
			pos++;
		}
}

void  PrintArray(int* array)
{
	int i = 0;
	for (i = 0; i < dim; i++)
		printf("%i ", array[i]);
	printf("\n");
}

;
int main()
{
	double start = clock();

	srand(time(NULL));
	for (int i = 0; i < dim; i++)
	{
		inputArray[i] =rand() % max;
	}
	PrintArray(inputArray);
	CountingSort();
	PrintArray(inputArray);





	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
	return 0;
}
