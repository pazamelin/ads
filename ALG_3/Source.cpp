#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#define dim 23

int sourceArray[dim] = { 1, 1, 1, 1, 666, - 666, 150, 200, - 11, - 17, 54, - 50, - 32,
12, 2, - 1, 4, 10, - 2, 6, 8, 15, -18};
int adjSummary = 18;

//-----------------------------------------------------------
int resultArray[dim] = { 0 };
int minArray[dim] = { 0 };
int minsize = dim;


int size_sourceArray = dim;
int size_resultArray = dim;

double start = clock();
void DFS(int amount,int currentStep, int currentState)
{
	/*
 	if (currentState < adjustedSummary)
	{
	*/
		currentState = currentState + sourceArray[currentStep];
	    resultArray[amount] = sourceArray[currentStep];
	    amount++;
		if ((currentState == adjSummary)&&(amount < minsize))
		{
			minsize = amount;
			for (int j = 0; j < amount; j++)
			{
				minArray[j] = resultArray[j];
			}
		
		                                                             //!!!1111111!!!
			if (minsize == 2)
			{
				for (int i = 0; i < minsize; i++)
					printf("%i ", minArray[i]);
				printf("\n");
				printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
				exit(0);
			}
		                                                             //!!!1111111!!!
			
			
		}
		else
		for (int i = currentStep + 1; i < size_sourceArray; i++)
		{
			DFS(amount,i, currentState);
		}

	//}
}
void doDFS()
{
	int i = 0;
	
	                                                            //!!!1111111!!!
	for (i = 0; i < size_sourceArray; i++)
		if (sourceArray[i] == adjSummary)
		{
			printf("%i\n",adjSummary);
			printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
			exit(0);

	    }
	                                                          //!!!11111111!!!
	for (i = 0; i < size_sourceArray; i++)
		DFS(0, i, 0);
}



;
int main()
{
	doDFS();
	for (int i = 0; i < minsize; i++)
		printf("%i ", minArray[i]);
	printf("\n");
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
	return 0;
}
