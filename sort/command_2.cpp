#include "sortings.cpp"

typedef void (*sortWithComp) (int arr[], int n, long long &count_compare);
typedef void (*sortWithTime) (int arr[], int n, double &time_use);

int sortFilter(char* name)
{
	if (!strcmp(name, "selection-sort"))
		return 0;
	else if (!strcmp(name, "insertion-sort"))
		return 1;
	else if (!strcmp(name, "bubble-sort"))
		return 2;
	else if (!strcmp(name, "shaker-sort"))
		return 3;
	else if (!strcmp(name, "shell-sort"))
		return 4;
	else if (!strcmp(name, "heap-sort"))
		return 5;
	else if (!strcmp(name, "merge-sort"))
		return 6;
	else if (!strcmp(name, "quick-sort"))
		return 7;
	else if (!strcmp(name, "counting-sort"))
		return 8;
	else if (!strcmp(name, "radix-sort"))
		return 9;
	else if (!strcmp(name, "flash-sort"))
		return 10;
	return -1;
}


int orderFilter(char* str)
{
    if (!strcmp(str, "-rand"))
        return 0;
    if (!strcmp(str, "-sorted"))
        return 1;
    if (!strcmp(str, "-rev"))
        return 2;
    if (!strcmp(str, "-nsorted"))
        return 3;
    return -1;
}

int main(int argc, char **argv)
{
	
    int nums = 0;
	if (!strcmp(argv[1], "-a"))
	{
		for (int i = 2; i < argc; i++)
		{
			if (i == 2)
			{
				cout << "ALGORITHM MODE" << endl;
				cout << "Algorithm  : ";
				if (sortFilter(argv[i]) == 0)
					cout << "Selection Sort" << endl;
				else if (sortFilter(argv[i]) == 1)
					cout << "Insertion Sort" << endl;
				else if (sortFilter(argv[i]) == 2)
					cout << "Bubble Sort" << endl;
				else if (sortFilter(argv[i]) == 3)
					cout << "Shaker Sort" << endl;
				else if (sortFilter(argv[i]) == 4)
					cout << "Shell Sort" << endl;
				else if (sortFilter(argv[i]) == 5)
					cout << "Heap Sort" << endl;
				else if (sortFilter(argv[i]) == 6)
					cout << "Merge Sort" << endl;
				else if (sortFilter(argv[i]) == 7)
					cout << "Quick Sort" << endl;
				else if (sortFilter(argv[i]) == 8)
					cout << "Counting Sort" << endl;
				else if (sortFilter(argv[i]) == 9)
					cout << "Radix Sort" << endl;
				else if (sortFilter(argv[i]) == 10)
					cout << "Flash Sort" << endl;
				else
					cout << argv[i] << endl;
			}
			if (i == 3)
			{
				cout << "Input size : " << argv[i] << endl;
				nums = atoi(argv[i]);
			}
			if (i == 4)
			{
				cout << "Input order: ";
				if (orderFilter(argv[i]) == 0)
					cout << "Randomize" << endl;
				else if (orderFilter(argv[i]) == 1)
					cout << "Sorted" << endl;
				else if (orderFilter(argv[i]) == 2)
					cout << "Reversed" << endl;
				else if (orderFilter(argv[i]) == 3)
					cout << "Nearly Sorted" << endl;

				long long count_compare = 0;
				int* arr = new int[nums];
				double time_use = 0;
				int dataType = 0;

				dataType = orderFilter(argv[i]);
				if (dataType == -1)
				{
					cout << "Error: unknown data type!\n";
					return 0;
				}

				GenerateData(arr, nums, dataType);

				// Array of functions
				sortWithComp compFunctions[] = 
				{
					selectionSortVerComp,
					insertionSortVerComp,
					bubbleSortVerComp,
					heapSortVerComp,
					mergeSortVerComp,
					quickSortVerComp,
					shakerSortVerComp,
					shellSortVerComp,
					radixSortVerComp,
					countingSortVerComp,
					flashSortVerComp,
				};
				sortWithTime timeFunctions[] =
				{
					selectionSortVerTime,
					insertionSortVerTime,
					bubbleSortVerTime,
					heapSortVerTime,
					mergeSortVerTime,
					quickSortVerTime,
					shakerSortVerTime,
					shellSortVerTime,
					radixSortVerTime,
					countingSortVerTime,
					flashSortVerTime,
				};
				// check function
				int index = sortFilter(argv[2]);
				if (index == -1)
				{
					cout << "Error: Unknown sort type!\n";
					return 0;
				}
				// Mode
				if (!strcmp(argv[5], "-both") || !strcmp(argv[5], "-comp"))
					compFunctions[index](arr, nums, count_compare);

				timeFunctions[index](arr, nums, time_use);

				if (!strcmp(argv[5], "-both"))
				{
					cout << "---------------------------" << endl;
					cout << "Running time (if required): " << time_use << " (ms)" << endl;
					cout << "Comparisons  (if required): " << count_compare << endl;
				}
				else if (!strcmp(argv[5], "-comp"))
				{
					cout << "---------------------------" << endl;
					cout << "Comparisons  (if required): " << count_compare << endl;
				}
				else if (!strcmp(argv[5], "-time"))
				{
					cout << "---------------------------" << endl;
					cout << "Running time (if required): " << time_use << " (ms)" << endl;
				}
				// Write file to "output.txt"
				ofstream out("output2.txt");
				if (out.fail())
				{
					cout << "Error opening file" << endl;
					out.close();
				}
				else
				{
					out << nums << endl;
					for (int _i = 0; _i < nums; _i++)
						out << arr[_i] << " ";
					out.close();
				}
			}
		}
	}
	else
		cout << "Error: unknown data type!" << endl;
	
	return 0;
}