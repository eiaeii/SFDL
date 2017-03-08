#include <cstdio>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void PrintArray(int *pArray, size_t nSize)
{
	for (size_t i = 0; i < nSize; ++i)
	{
		printf_s("%d\t", pArray[i]);
	}

	printf_s("\n");
}

void InsertSort(int *pArray, size_t nLength)
{
	if (nullptr == pArray || 0 == nLength)
		return;

	size_t j = 0;
	int nTemp = 0;

	for (size_t i = 1; i < nLength; ++i)
	{
		nTemp = pArray[i];
		
		for (j = i; j > 0 && nTemp < pArray[j - 1]; --j)
		{
			pArray[j] = pArray[j - 1];
			PrintArray(pArray, SIZE);
		}

		pArray[j] = nTemp;
		PrintArray(pArray, SIZE);
		printf_s("\n");
	}
}

int main()
{
	srand((unsigned int)time(nullptr));
	int objTest[SIZE] = { 0 };
	for (size_t i = 0; i < SIZE; ++i)
	{
		objTest[i] = rand() % 100;
	}

	printf_s("排序前：\n");
	PrintArray(objTest, SIZE);

	printf_s("排序过程：\n");
	InsertSort(objTest, SIZE);

	printf_s("排序后：\n");
	PrintArray(objTest, SIZE);

	system("pause");

	return 0;
}