/*
Zak Rawles
5341679
2/23/24
COP3502C-0040
Lab Assignment 6


*/

#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	//base
    if (low > high) {
        return -1; //trigger else in line 84
    }

	//determine middle of the array
    int middle = (high + low) / 2; 

	//if middle is found matches perameter value
    if (numbers[middle] == value) {

        return middle;
    } 
	//middle is greater, check first half of array
	else if (numbers[middle] > value) {
        return search(numbers, low, middle - 1, value); 
    } 
	//middle is greater, check second half of array
	else {
        return search(numbers, middle + 1, high, value); 
    }
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}