#include <iostream> 
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n, long long &count_compare);
void selectionSort_noComp(int arr[], int n, double &time_use);

void heapRebuild(int start, int arr[], int n, long long& count_compare){
	int leftChild = 2 * start + 1; // A left child must exist
	if (++count_compare && leftChild >= n)return;
	int largerChild = leftChild; // Make assumption about larger child
	int rightChild = 2 * start + 2; // A right child might not exist
	if (++count_compare && rightChild < n){ // Whether a right child exists
		// A right child exists; check whether it is larger
		if (++count_compare && arr[rightChild] > arr[largerChild])
		largerChild = rightChild; // Assumption was wrong
	}
	// If arr[start] is smaller than the larger child, swap values
	if (++count_compare && arr[start] < arr[largerChild]){
		swap(arr[largerChild], arr[start]);
		heapRebuild(largerChild, arr, n, count_compare); // Recursion at that child
	}
}
//heapSort count comparison
void heapSort(int arr[], int n, long long& count_compare){
	// Build initial heap
	for (int index = (n - 1) / 2; ++count_compare && index >= 0; index--)
		heapRebuild(index, arr, n, count_compare);
	swap(arr[0], arr[n - 1]); // swap the largest element to the end
	int heapSize = n - 1; // Heap region size decreases by 1
	while (++count_compare && heapSize > 1) {
		heapRebuild(0, arr, heapSize, count_compare);
		heapSize--;
		swap(arr[0], arr[heapSize]);
	}
}

void merge(int arr[], int first, int mid, int last, long long& count_compare){
	// Initialize the local indices to indicate the subarrays
	int first1 = first, last1 = mid; // The first subarray
	int first2 = mid + 1, last2 = last; // The second subarray
	// Copy the smaller element into the temp array
	int tempArr[500000]; // Temporary array
	int index = first1; // Next available location in tempArr
	while ((++count_compare && first1 <= last1) && (++count_compare && first2 <= last2)) {
		if (++count_compare && arr[first1] <= arr[first2])
			tempArr[index++] = arr[first1++];
		else
			tempArr[index++] = arr[first2++];
	}
	while (++count_compare && first1 <= last1) // Finish the first subarray, if necessary
		tempArr[index++] = arr[first1++];
	while (++count_compare && first2 <= last2) // Finish the second subarray, if necessary
		tempArr[index++] = arr[first2++];
	// Copy the result back into the original array
	for (index = first; ++count_compare && index <= last; ++index)
		arr[index] = tempArr[index];
}
void mergeSortDo(int arr[], int first, int last, long long& count_compare){
	if (++count_compare && first < last) {
		int mid = (first + last) / 2; // Index of midpoint
			mergeSortDo(arr, first, mid, count_compare); // Sort left half
			mergeSortDo(arr, mid + 1, last, count_compare); // Sort right half
			merge(arr, first, mid, last, count_compare); // Merge the two halves
		}
}
//mergeSort count comparison
void mergeSort(int arr[], int n, long long& count_compare){
	mergeSortDo(arr, 0, n - 1, count_compare);
}

void quickSortDo(int arr[], int first, int last, long long& count_compare){
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (++count_compare && arr[i] < pivot) i++;
		while (++count_compare && arr[j] > pivot) j--;
		if (++count_compare && i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (++count_compare && i <= j);
	if (++count_compare && first < j) quickSortDo(arr, first, j, count_compare);
	if (++count_compare && i < last) quickSortDo(arr, i, last, count_compare);
}
//quickSort count comparison
void quickSort(int arr[], int n, long long& count_compare){
	quickSortDo(arr, 0, n - 1, count_compare);
}

void heapRebuild_noComp(int start, int arr[], int n){
	int leftChild = 2 * start + 1; // A left child must exist
	if (leftChild >= n) return;
	int largerChild = leftChild; // Make assumption about larger child
	int rightChild = 2 * start + 2; // A right child might not exist
	if (rightChild < n){ // Whether a right child exists
		// A right child exists; check whether it is larger
		if (arr[rightChild] > arr[largerChild])
		largerChild = rightChild; // Assumption was wrong
	}
	// If arr[start] is smaller than the larger child, swap values
	if (arr[start] < arr[largerChild]){
		swap(arr[largerChild], arr[start]);
		heapRebuild_noComp(largerChild, arr, n); // Recursion at that child
	}
}
//heapSort time
void heapSort_noComp(int arr[], int n, double& time){
	clock_t start, end;
	start = double(clock());
	
	// Build initial heap
	for (int index = (n - 1) / 2; index >= 0; index--)
	heapRebuild_noComp(index, arr, n);
	swap(arr[0], arr[n - 1]); // swap the largest element to the end
	int heapSize = n - 1; // Heap region size decreases by 1
	while (heapSize > 1) {
		heapRebuild_noComp(0, arr, heapSize);
		heapSize--;
		swap(arr[0], arr[heapSize]);
	}
	
	end = double(clock());
	time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

void merge_noComp(int arr[], int first, int mid, int last){
	// Initialize the local indices to indicate the subarrays
	int first1 = first, last1 = mid; // The first subarray
	int first2 = mid + 1, last2 = last; // The second subarray
	// Copy the smaller element into the temp array
	int tempArr[500000]; // Temporary array
	int index = first1; // Next available location in tempArr
	while ((first1 <= last1) && (first2 <= last2)) {
		if (arr[first1] <= arr[first2])
			tempArr[index++] = arr[first1++];
		else
			tempArr[index++] = arr[first2++];
	}
	while (first1 <= last1) // Finish the first subarray, if necessary
	tempArr[index++] = arr[first1++];
	while (first2 <= last2) // Finish the second subarray, if necessary
	tempArr[index++] = arr[first2++];
	// Copy the result back into the original array
	for (index = first; index <= last; ++index)
		arr[index] = tempArr[index];
}
void mergeSortDo_noComp(int arr[], int first, int last){
	if (first < last) {
		int mid = (first + last) / 2; // Index of midpoint
			mergeSortDo_noComp(arr, first, mid); // Sort left half
			mergeSortDo_noComp(arr, mid + 1, last); // Sort right half
			merge_noComp(arr, first, mid, last); // Merge the two halves
		}
}
//mergeSort time
void mergeSort_noComp(int arr[], int n, double& time){
	clock_t start, end;
	start = double(clock());
	
	mergeSortDo_noComp(arr, 0, n - 1);
	
	end = double(clock());
	time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

void quickSortDo_noComp(int arr[], int first, int last){
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (i <= j);
	if (first < j) quickSortDo_noComp(arr, first, j);
	if (i < last) quickSortDo_noComp(arr, i, last);
}
//quickSort time
void quickSort_noComp(int arr[], int n, double& time){
	clock_t start, end;
	start = double(clock());
	
	quickSortDo_noComp(arr, 0, n - 1);
	
	end = double(clock());
	time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}
//from Nguyen Ngoc Thao

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
