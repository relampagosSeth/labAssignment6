#include <stdio.h>
#include <stdlib.h>


int search(int numbers[], int low, int high, int value) 
{

  int index = (high + low) / 2;

  //printf("Index is at %d\n", index);
  
  if (numbers[index] == value) {
    return index;
  }

  if (low > high || high < low) {
    return -1;
  }

  if (numbers[index] < value) {
    return search(numbers, index + 1, high, value);
  }

  else {
    return search(numbers, low, index - 1, value);
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
      printf("Item %d exists in the number array at index %d!\n", value, index);
    }
    else
    {
      printf("Item %d does not exist in the number array!\n", value);
    }

    free(numArray);
  }

  fclose(inFile);
}