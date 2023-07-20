#include <iostream> 
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n, long long &count_compare);
void selectionSort_noComp(int arr[], int n, double &time_use);

void radixSort(int arr[], int n, long long &count_compare)
{
	// find max value
	int maxValue = -1;

	for (int i = 0; i < n; ++i, ++count_compare)
	{
		++count_compare;
		if (maxValue < arr[i])
			maxValue = arr[i];
	}
	
	// digits
	int digits = 0, div = 0;
	do
	{
		digits ++;
		div = maxValue / pow(10, digits);
	} while (++count_compare && div > 0);
	
	// bucket
	int** tempArr = new int*[10];
	for (int i = 0; i < 10; ++i, ++count_compare)
		tempArr[i] = new int[n];
	int tempCount[10];

	// radix sort
	for (int i = 0; i < digits; ++i, ++count_compare)
	{
		int exp = pow(10, i);
		for (int j = 0; j < 10; ++j, ++count_compare)
			tempCount[j] = 0;
		for (int j = 0; j < n; ++j, ++count_compare)
		{
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0;
		for (int j = 0; j < 10; ++j, ++count_compare)
			for (int k = 0; k < tempCount[j]; ++k, ++count_compare)
				arr[idx++] = tempArr[j][k];
	}
}

void radixSort_noComp(int arr[], int n, double &time_use)
{
	clock_t start, end;
	start = clock();
	// find max value
	int maxValue = -1;

	for (int i = 0; i < n; ++i)
	{
		if (maxValue < arr[i])
		{
			maxValue = arr[i];
		}
	}
	
	// digits
	int digits = 0, div = 0;
	do
	{
		digits ++;
		div = maxValue / pow(10, digits);
	} while (div > 0);
	
	// bucket
	int** tempArr = new int*[10];
	for (int i = 0; i < 10; ++i)
		tempArr[i] = new int[n];
	int tempCount[10];

	// radix sort
	for (int i = 0; i < digits; ++i)
	{
		int exp = pow(10, i);
		for (int j = 0; j < 10; ++j)
			tempCount[j] = 0;
		for (int j = 0; j < n; ++j)
		{
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0;
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < tempCount[j]; ++k)
				arr[idx++] = tempArr[j][k];
	}
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
}

void shakerSort(int arr[], int n, long long &count_compare)
{
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; j >= left; --j, ++count_compare)
        {
            ++count_compare;
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j, ++count_compare)
        {
            ++count_compare;
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (++ count_compare && left <= right);
    
}

void shakerSort_noComp(int arr[], int n, double &time_use)
{
	clock_t start, end;
	start = clock();
    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int j = right; j >= left; --j)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (left <= right);  
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC; 
}


void shellSort(int arr[], int n, long long &count_compare)
{
	int gap, i, j, temp;
	for(gap = n / 2; gap > 0; gap /= 2, ++count_compare){
		for(i = gap; i < n; i++, ++count_compare){
			temp = arr[i];
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap, count_compare += 2){
				arr[j] = arr[j - gap];				
			}
			arr[j] = temp;
		}
    }
}

void shellSort_noComp(int arr[], int n, double &time_use)
{
	clock_t start, end;
	start = clock();
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
}
// Ref: https://codelearn.io/learning/data-structure-and-algorithms/856660