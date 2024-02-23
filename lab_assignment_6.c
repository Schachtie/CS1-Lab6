#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	//Check if last recursive step has been reached
	if (low == high)
	{
		return -1;
	}
	//Find middle index
	int searchIndex = (low + high) / 2;
	
	//Check for value found
	if (numbers[searchIndex] == value)
	{
		return searchIndex;
	}
	//If not found, call recursion with new bounds based on whether current array value is > or < value
	if (numbers[searchIndex] > value)
	{
		return search(numbers, low, searchIndex, value);
	}
	//Uses (searchIndex + 1) to compensate for when low/high are +- 1 of each other (avoids infinite recursion)
	return search(numbers, searchIndex + 1, high, value);
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