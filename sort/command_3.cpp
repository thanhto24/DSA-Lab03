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

// a.exe -a radix-sort 70000 -comp (0 1 2 3 4)
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
				cout << "Algorithm : ";
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
				cout << "Input size: " << argv[i] << endl;
				nums = atoi(argv[i]);
			}
            if (i == 4)
            {
                long long count_compare = 0;
                double time_use = 0;
                int *arr_1 = new int[nums];
                int *arr_2 = new int[nums];
                int *arr_3 = new int[nums];
                int *arr_4 = new int[nums];
                int dataType;
                int index = sortFilter(argv[2]);

                if (index == -1)
                {
                    cout << "Error: Unknown data type!" << endl;
                    return 0;
                }

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

                cout << "\nInput order: Randomize" << endl;
                cout << "---------------------------" << endl;
                dataType = 0;
                GenerateData(arr_1, nums, dataType);
                
                if(!strcmp(argv[4], "-both") || !strcmp(argv[4],"-comp"))
                    compFunctions[index](arr_1, nums, count_compare);
                timeFunctions[index](arr_1, nums, time_use);

                if (!strcmp(argv[4], "-both"))
                {
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                
                ofstream ofs_1("input_1.txt");
                if (ofs_1.fail())
                {
                    cout << "\nError: The file cannot created !!!" << endl;
                    ofs_1.close();
                }
                else
                {
                    ofs_1 << nums << endl;
                    for (int i = 0; i < nums; i++)
                        ofs_1 << arr_1[i] << " ";
                    ofs_1.close();   
                }

                cout << "\nInput order: Nearly Sorted" << endl;
                cout << "---------------------------" << endl;
                dataType = 3;
                GenerateData(arr_2, nums, dataType);
                
                if(!strcmp(argv[4], "-both") || !strcmp(argv[4],"-comp"))
                    compFunctions[index](arr_2, nums, count_compare);
                timeFunctions[index](arr_2, nums, time_use);

                if (!strcmp(argv[4], "-both"))
                {
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                
                ofstream ofs_2("input_2.txt");
                if (ofs_2.fail())
                {
                    cout << "\nError: The file cannot created !!!" << endl;
                    ofs_2.close();
                }
                else
                {
                    ofs_2 << nums << endl;
                    for (int i = 0; i < nums; i++)
                        ofs_2 << arr_2[i] << " ";
                    ofs_2.close();   
                }

                cout << "\nInput order: Sorted" << endl;
                cout << "---------------------------" << endl;
                dataType = 1;
                GenerateData(arr_3, nums, dataType);
                
                if(!strcmp(argv[4], "-both") || !strcmp(argv[4],"-comp"))
                    compFunctions[index](arr_3, nums, count_compare);
                timeFunctions[index](arr_3, nums, time_use);

                if (!strcmp(argv[4], "-both"))
                {
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                
                ofstream ofs_3("input_3.txt");
                if (ofs_3.fail())
                {
                    cout << "\nError: The file cannot created !!!" << endl;
                    ofs_3.close();
                }
                else
                {
                    ofs_3 << nums << endl;
                    for (int i = 0; i < nums; i++)
                        ofs_3 << arr_3[i] << " ";
                    ofs_3.close();   
                }

                cout << "\nInput order: Reversed" << endl;
                cout << "---------------------------" << endl;
                dataType = 2;
                GenerateData(arr_4, nums, dataType);
                
                if(!strcmp(argv[4], "-both") || !strcmp(argv[4],"-comp"))
                    compFunctions[index](arr_4, nums, count_compare);
                timeFunctions[index](arr_4, nums, time_use);

                if (!strcmp(argv[4], "-both"))
                {
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (ms)" << endl;
                
                ofstream ofs_4("input_4.txt");
                if (ofs_4.fail())
                {
                    cout << "\nError: The file cannot created !!!" << endl;
                    ofs_4.close();
                }
                else
                {
                    ofs_4 << nums << endl;
                    for (int i = 0; i < nums; i++)
                        ofs_4 << arr_4[i] << " ";
                    ofs_4.close();   
                }
            }
        }
    }
    else
        cout << "Error: Unknown data type!" << endl;

    return 0;
}