#include "DataGenerator.cpp"
#include <cstring>
#include <sstream>

// TÔ QUỐC THANH_22127388: Selection Sort && Insertion Sort && Bubble Sort
void selectionSortVerComp(int arr[], int n, long long &count_compare)
{

}

void selectionSortVerTime(int arr[], int n, double &time_use)
{

}

void insertionSortVerComp(int arr[], int n, long long &count_compare)
{

}

void insertionSortVerTime(int arr[], int n, double &time_use)
{

}

void bubbleSortVerComp(int arr[], int n, long long &count_compare)
{

}

void bubbleSortVerTime(int arr[], int n, double &time_use)
{

}

// NGÔ VĂN KHẢI_22127174: Heap Sort && Merge Sort && Quick Sort
// Heap Sort: Counting the number of comparisons
void heapRebuildVerComp(int start, int arr[], int n, long long& count_compare){
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
		heapRebuildVerComp(largerChild, arr, n, count_compare); // Recursion at that child
	}
}

void heapSortVerComp(int arr[], int n, long long& count_compare){
	// Build initial heap
	for (int index = (n - 1) / 2; ++count_compare && index >= 0; index--)
		heapRebuildVerComp(index, arr, n, count_compare);
	swap(arr[0], arr[n - 1]); // swap the largest element to the end
	int heapSize = n - 1; // Heap region size decreases by 1
	while (++count_compare && heapSize > 1) {
		heapRebuildVerComp(0, arr, heapSize, count_compare);
		heapSize--;
		swap(arr[0], arr[heapSize]);
	}
}

// Heap Sort: Calculating the time of algorithm
void heapRebuildVerTime(int start, int arr[], int n){
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
		heapRebuildVerTime(largerChild, arr, n); // Recursion at that child
	}
}

void heapSortVerTime(int arr[], int n, double& time_use){
	clock_t start, end;
	start = double(clock());
	
	// Build initial heap
	for (int index = (n - 1) / 2; index >= 0; index--)
	heapRebuildVerTime(index, arr, n);
	swap(arr[0], arr[n - 1]); // swap the largest element to the end
	int heapSize = n - 1; // Heap region size decreases by 1
	while (heapSize > 1) {
		heapRebuildVerTime(0, arr, heapSize);
		heapSize--;
		swap(arr[0], arr[heapSize]);
	}
	
	end = double(clock());
	time_use = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

// Merge Sort: Counting the number of comparisons
void mergeSortRebuildVerComp(int arr[], int first, int mid, int last, long long& count_compare){
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

void mergeSortDoVerComp(int arr[], int first, int last, long long& count_compare){
	if (++count_compare && first < last) {
		int mid = (first + last) / 2; // Index of midpoint
			mergeSortDoVerComp(arr, first, mid, count_compare); // Sort left half
			mergeSortDoVerComp(arr, mid + 1, last, count_compare); // Sort right half
			mergeSortRebuildVerComp(arr, first, mid, last, count_compare); // Merge the two halves
		}
}

void mergeSortVerComp(int arr[], int n, long long& count_compare){
	mergeSortDoVerComp(arr, 0, n - 1, count_compare);
}

// Merge Sort: Calculating the time of algorithm
void mergeSortRebuildVerTime(int arr[], int first, int mid, int last){
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

void mergeSortDoVerTime(int arr[], int first, int last){
	if (first < last) {
		int mid = (first + last) / 2; // Index of midpoint
			mergeSortDoVerTime(arr, first, mid); // Sort left half
			mergeSortDoVerTime(arr, mid + 1, last); // Sort right half
			mergeSortRebuildVerTime(arr, first, mid, last); // Merge the two halves
		}
}

void mergeSortVerTime(int arr[], int n, double& time){
	clock_t start, end;
	start = double(clock());
	
	mergeSortDoVerTime(arr, 0, n - 1);
	
	end = double(clock());
	time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

// Quick Sort: Counting the number of comparisons
void quickSortDoVerComp(int arr[], int first, int last, long long& count_compare){
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
	if (++count_compare && first < j) quickSortDoVerComp(arr, first, j, count_compare);
	if (++count_compare && i < last) quickSortDoVerComp(arr, i, last, count_compare);
}

void quickSortVerComp(int arr[], int n, long long& count_compare){
	quickSortDoVerComp(arr, 0, n - 1, count_compare);
}

// Quick Sort: Calculating the time of algorithm
void quickSortDoVerTime(int arr[], int first, int last){
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
	if (first < j) quickSortDoVerTime(arr, first, j);
	if (i < last) quickSortDoVerTime(arr, i, last);
}

void quickSortVerTime(int arr[], int n, double& time){
	clock_t start, end;
	start = double(clock());
	
	quickSortDoVerTime(arr, 0, n - 1);
	
	end = double(clock());
	time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

// THÁI HUYỄN TÙNG_22127441: Radix Sort && Shaker Sort && Shell Sort
// Radix Sort: Counting the number of comparisons
void radixSortVerComp(int arr[], int n, long long &count_compare)
{
	// find max value of the array
	int maxValue = -1;

	for (int i = 0; ++count_compare && i < n; ++i)
	{
		if (++count_compare && maxValue < arr[i])
			maxValue = arr[i];
	}
	
	// find the max number of digits
	int digits = 0, div = 0;
	do
	{
		digits ++;
		div = maxValue / pow(10, digits);
	} while (++count_compare && div > 0);
	
	// declare variables for temp buckets
	int** tempArr = new int*[10];
	for (int i = 0; ++count_compare && i < 10; ++i)
		tempArr[i] = new int[n];
	int tempCount[10];

	// radix sort algorithm
    // form groups of numbers and combine groups
	for (int i = 0; ++count_compare && i < digits; ++i)
	{
		int exp = pow(10, i);
		for (int j = 0; ++count_compare && j < 10; ++j) // reset the counting
			tempCount[j] = 0;
		for (int j = 0; ++count_compare && j < n; ++j)  // form groups
		{
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0;    // combine groups
		for (int j = 0; ++count_compare && j < 10; ++j)
			for (int k = 0; ++count_compare && k < tempCount[j]; ++k)
				arr[idx++] = tempArr[j][k];
	}
}

// Radix Sort: Calculating the time of algorithm
void radixSortVerTime(int arr[], int n, double &time_use)
{
	clock_t start, end;
	start = clock();

	// find max value of the array
	int maxValue = -1;

	for (int i = 0; i < n; ++i)
	{
		if (maxValue < arr[i])
		{
			maxValue = arr[i];
		}
	}
	
	// find the max number of digits
	int digits = 0, div = 0;
	do
	{
		digits ++;
		div = maxValue / pow(10, digits);
	} while (div > 0);
	
	// declare variables for temp buckets
	int** tempArr = new int*[10];
	for (int i = 0; i < 10; ++i)
		tempArr[i] = new int[n];
	int tempCount[10];

	// radix sort
    // form groups of numbers and combine groups
	for (int i = 0; i < digits; ++i)
	{
		int exp = pow(10, i);
		for (int j = 0; j < 10; ++j)    // reset the counting
			tempCount[j] = 0;
		for (int j = 0; j < n; ++j)     // form groups
		{
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0; // combine groups
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < tempCount[j]; ++k)
				arr[idx++] = tempArr[j][k];
	}
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
}

// Shaker Sort: Counting the number of comparisons
void shakerSortVerComp(int arr[], int n, long long &count_compare)
{
    int left = 1, right = n - 1, k = n - 1;
    do
    {
		// sort from right to left to guarantee that the small elements are sorted at the top of the array.
        for (int j = right; j >= left; --j, ++count_compare)
        {
            ++count_compare;
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;	// because elements from the beginning of the array to the "k" were sorted so we need to sort from the "k + 1" to the end of the array.
		// sort from left to right to guarantee that the large elements are sorted at the end of the array.
        for (int j = left; j <= right; ++j, ++count_compare)
        {
            ++count_compare;
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;	// because elements from "k" to the end of the array were sorted so we need to sort from the "k - 1" to the beginning of the array.
    } while (++ count_compare && left <= right);	// continue iterating until the left equals to the right.
    
}

// Shaker Sort: Calculating the time of algorithm
void shakerSortVerTime(int arr[], int n, double &time_use)
{
	clock_t start, end;
	start = clock();
    int left = 1, right = n - 1, k = n - 1;
    do
    {
		// sort from right to left to guarantee that the small elements are sorted at the top of the array.
        for (int j = right; j >= left; --j)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;	// because elements from the beginning of the array to the "k" were sorted so we need to sort from the "k + 1" to the end of the array.
		// sort from left to right to guarantee that the large elements are sorted at the end of the array.
        for (int j = left; j <= right; ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;	// because elements from "k" to the end of the array were sorted so we need to sort from the "k - 1" to the beginning of the array.
    } while (left <= right);   // continue iterating until the left equals to the right.
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC; 
}

// Shell Sort: Counting the number of comparisons
void shellSortVerComp(int arr[], int n, long long &count_compare)
{
	int gap, i, j, temp;
	// Start with a big gap, then reduce the gap
	for(gap = n / 2; gap > 0; gap /= 2, ++count_compare)
	{
		// Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted 
		for(i = gap; i < n; i++, ++count_compare){
			// add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
			temp = arr[i];
			// shift earlier gap-sorted elements up until the correct 
            // location for arr[i] is found
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap, count_compare += 2){
				arr[j] = arr[j - gap];				
			}
			//  put temp (the original arr[i]) in its correct location
			arr[j] = temp;
		}
    }
}

// Shell Sort: Calculating the time of algorithm
void shellSortVerTime(int arr[], int n, double &time_use)
{
	clock_t start, end;
	start = clock();
    int gap, i, j, temp;
	// Start with a big gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2)
    {
		// Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted 
        for (i = gap; i < n; i++)
        {
			// add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            temp = arr[i];
			// shift earlier gap-sorted elements up until the correct 
            // location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
			//  put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
}

// LÊ PHƯỚC PHÁT_22127322: Counting Sort && Flash Sort
// Counting Sort: Counting the number of comparisons
void countingSortVerComp(int arr[], int n, long long &count_compare)
{
    count_compare = 0;

    // find the max value of the array
    int MAX = arr[0];
    for (int i = 1; ++count_compare && i < n; i++)
        if (++count_compare && arr[i] > MAX)
            MAX = arr[i];

    // perform the distribution counting
    int *f = new int [MAX + 1] {0};
    for (int i = 0; ++count_compare && i < n; i++)
        f[arr[i]]++;
    
    // accumulate sum of frequencies
    for (int i = 1; ++count_compare && i <= MAX; i++)
        f[i] = f[i - 1] + f[i];
    
    // distrbute values to their final positions
    int *b = new int[n];
    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0; ++count_compare && i < n; i++)
        arr[i] = b[i];
}

// Counting Sort: Calculating the time of algorithm
void countingSortVerTime(int arr[], int n, double &time_use)
{
    clock_t start, end;
    start = double(clock());

    // find the max value of the array
    int MAX = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > MAX)
            MAX = arr[i];

    // perform the distribution counting
    int *f = new int [MAX + 1] {0};
    for (int i = 0; i < n; i++)
        f[arr[i]]++;
    
    // accumulate the sum of frequencies
    for (int i = 1; i <= MAX; i++)
        f[i] = f[i - 1] + f[i];
    
    // distrbute values to their final positions
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = b[i];

    end = double(clock());
    time_use = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

// Flash Sort: Counting the number of comparisons
void flashSortVerComp(int arr[], int n, long long &count_compare) 
{
    count_compare = 0;

    // find the max and min value of the array
    int MAX = 0;
    int MIN = arr[0];
    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && arr[i] > arr[MAX])
            MAX = i;
        MIN = min(MIN, arr[i]);
    }
    if (++count_compare && arr[MAX] == MIN)
        return;
    
    // calculate the number of buckets
    int m = 0.45 * n;
    int *distribution = new int [m]{0};
    distribution[0] = -1;
    double k = (m - 1.0) / (arr[MAX] - MIN);

    // count the number of elements in each bucket
    for (int i = 0; ++count_compare && i < n; i++)
    {
        int j = k * (arr[i] - MIN);
        distribution[j]++;
    }
    for (int j = 1; ++ count_compare && j < m; j++)
        distribution[j] += distribution[j - 1];

    // permutation all elements of buckets to put them in the right position
    swap(arr[MAX], arr[0]);
    for (int i = 0, j = 0, l = m - 1; ++count_compare && i < n;)
    {
        for(; ++count_compare && j > distribution[l];)
            l = k * (arr[++j] - MIN);
        int temp = arr[j];
        for (; ++count_compare && j <= distribution[l]; i++)
        {
            l = k * (temp - MIN);
            swap(temp, arr[distribution[l]--]);
        }
    }
    
    // insertion sort to sort the elements in the buckets
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (++count_compare && j >= 0 && ++count_compare && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Flash Sort: Calculating the time of algorithm
void flashSortVerTime(int arr[], int n, double &time_use)
{
    clock_t start, end;
    start = double(clock());
    int MAX = 0;
    int MIN = arr[0];

    // find the max and min value of the array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[MAX])
            MAX = i;
        MIN = min(MIN, arr[i]);
    }
    if (arr[MAX] == MIN)
        return;
    
    // calculate the number of buckets
    int m = 0.45 * n;
    int *distribution = new int [m]{0};
    distribution[0] = -1;
    double k = (m - 1.0) / (arr[MAX] - MIN);

    // count the number of elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int j = k * (arr[i] - MIN);
        distribution[j]++;
    }
    for (int j = 1; j < m; j++)
        distribution[j] += distribution[j - 1];

    // permutation all elements of buckets to put them in the right position
    swap(arr[MAX], arr[0]);
    for (int i = 0, j = 0, l = m - 1; i < n;)
    {
        for(;j > distribution[l];)
            l = k * (arr[++j] - MIN);
        int temp = arr[j];
        for (;j <= distribution[l]; i++)
        {
            l = k * (temp - MIN);
            swap(temp, arr[distribution[l]--]);
        }
    }
    
    // insertion sort to sort the elements in the buckets
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    end = double(clock());
    time_use = (double(end)- double(start)) / double(CLOCKS_PER_SEC);
}