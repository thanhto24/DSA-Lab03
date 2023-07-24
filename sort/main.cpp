#include "sortings.cpp"

typedef void (*sortWithComp)(int arr[], int n, long long &count_compare);
typedef void (*sortWithTime)(int arr[], int n, double &time_use);

int sortFilter(char *name)
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

int orderFilter(char *str)
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

void cpyArr(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

void command_1(int argc, char **argv)
{
    int nums = 0;
    int *arr = NULL;
    for (int i = 2; i < argc; i++)
    {
        if (i == 2)
        {
            cout << "ALGORITHM MODE: " << endl;
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
            cout << "Input file: " << argv[i] << endl;
            ifstream ifs(argv[i]);
            if (ifs.fail())
            {
                cout << "Error opening file" << endl;
                return;
            }
            else
            {
                ifs >> nums;
                arr = new int[nums];
                int index = 0;
                while (!ifs.eof())
                    ifs >> arr[index++];
            }
        }
        if (i == 4)
        {
            cout << "Input size: " << nums << endl;
            long long count_compare = 0;
            double time_use = 0;

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
                return;
            }
            // Mode
            if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
                compFunctions[index](arr, nums, count_compare);

            timeFunctions[index](arr, nums, time_use);

            if (!strcmp(argv[4], "-both"))
            {
                cout << "---------------------------" << endl;
                cout << "Running time (if required): " << time_use << " (ms)" << endl;
                cout << "Comparisons  (if required): " << count_compare << endl;
            }
            else if (!strcmp(argv[4], "-comp"))
            {
                cout << "---------------------------" << endl;
                cout << "Comparisons  (if required): " << count_compare << endl;
            }
            else if (!strcmp(argv[4], "-time"))
            {
                cout << "---------------------------" << endl;
                cout << "Running time (if required): " << time_use << " (ms)" << endl;
            }
            // Write file to "output.txt"
            ofstream out("output.txt");
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
    return;
}

void command_2(int argc, char **argv)
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
                int *arr = new int[nums];
                double time_use = 0;
                int dataType = 0;

                dataType = orderFilter(argv[i]);
                if (dataType == -1)
                {
                    cout << "Error: unknown data type!\n";
                    return;
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
                    return;
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

    return;
}

void command_3(int argc, char **argv)
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
                    return;
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

                if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
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

                if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
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

                if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
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

                if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
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

    return;
}

void command_4(int argc, char **argv)
{
    int n;
    ifstream fin(argv[4]);
    if (!fin)
        return;
    fin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];
    fin.close();
    int *b = new int[n];
    cpyArr(b, a, n);
    cout << "Algorithm: ";
    if (sortFilter(argv[2]) == 0)
        cout << "Selection Sort";
    else if (sortFilter(argv[2]) == 1)
        cout << "Insertion Sort";
    else if (sortFilter(argv[2]) == 2)
        cout << "Bubble Sort";
    else if (sortFilter(argv[2]) == 3)
        cout << "Shaker Sort";
    else if (sortFilter(argv[2]) == 4)
        cout << "Shell Sort";
    else if (sortFilter(argv[2]) == 5)
        cout << "Heap Sort";
    else if (sortFilter(argv[2]) == 6)
    cout << "Merge Sort";
    else if (sortFilter(argv[2]) == 7)
    cout << "Quick Sort";
    else if (sortFilter(argv[2]) == 8)
        cout << "Counting Sort";
    else if (sortFilter(argv[2]) == 9)
        cout << "Radix Sort";
    else if (sortFilter(argv[2]) == 10)
        cout << "Flash Sort";
    else
        cout << argv[2];
    cout << " | ";
    if (sortFilter(argv[3]) == 0)
        cout << "Selection Sort" << endl;
    else if (sortFilter(argv[3]) == 1)
        cout << "Insertion Sort" << endl;
    else if (sortFilter(argv[3]) == 2)
        cout << "Bubble Sort" << endl;
    else if (sortFilter(argv[3]) == 3)
        cout << "Shaker Sort" << endl;
    else if (sortFilter(argv[3]) == 4)
        cout << "Shell Sort";
    else if (sortFilter(argv[3]) == 5)
        cout << "Heap Sort" << endl;
    else if (sortFilter(argv[3]) == 6)
    cout << "Merge Sort" << endl;
    else if (sortFilter(argv[3]) == 7)
    cout << "Quick Sort" << endl;
    else if (sortFilter(argv[3]) == 8)
        cout << "Counting Sort" << endl;
    else if (sortFilter(argv[3]) == 9)
        cout << "Radix Sort" << endl;
    else if (sortFilter(argv[3]) == 10)
        cout << "Flash Sort" << endl;
    else
        cout << argv[3] << endl;

    cout << "Input file: " << argv[4] << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------" << endl;
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
    long long count_compare1 = 0, count_compare2 = 0;
    double time_use1 = 0, time_use2 = 0;
    int index1 = sortFilter(argv[2]);
    int index2 = sortFilter(argv[3]);
    timeFunctions[index1](a, n, time_use1);
    cpyArr(a, b, n);
    timeFunctions[index2](a, n, time_use2);
    cpyArr(a, b, n);
    cout << "Runing time: " << time_use1 << "(ms) | " << time_use2 << "(ms)" << endl;

    compFunctions[index1](a, n, count_compare1);
    cpyArr(a, b, n);
    compFunctions[index2](a, n, count_compare2);
    cpyArr(a, b, n);

    cout << "Comparisions: " << count_compare1 << " | " << count_compare2 << endl;

    delete[] a;
    delete[] b;
}

void command_5(int argc, char **argv)
{
    int n;
    n = atoi(argv[4]);
    int *a = new int[n];
    GenerateData(a, n, orderFilter(argv[5]));
    int *b = new int[n];
    cpyArr(b, a, n);
    cout << "Algorithm: ";
    if (sortFilter(argv[2]) == 0)
        cout << "Selection Sort";
    else if (sortFilter(argv[2]) == 1)
        cout << "Insertion Sort";
    else if (sortFilter(argv[2]) == 2)
        cout << "Bubble Sort";
    else if (sortFilter(argv[2]) == 3)
        cout << "Shaker Sort";
    else if (sortFilter(argv[2]) == 4)
        cout << "Shell Sort";
    else if (sortFilter(argv[2]) == 5)
        cout << "Heap Sort";
    else if (sortFilter(argv[2]) == 6)
    cout << "Merge Sort";
    else if (sortFilter(argv[2]) == 7)
    cout << "Quick Sort";
    else if (sortFilter(argv[2]) == 8)
        cout << "Counting Sort";
    else if (sortFilter(argv[2]) == 9)
        cout << "Radix Sort";
    else if (sortFilter(argv[2]) == 10)
        cout << "Flash Sort";
    else
        cout << argv[2];
    cout << " | ";
    if (sortFilter(argv[3]) == 0)
        cout << "Selection Sort" << endl;
    else if (sortFilter(argv[3]) == 1)
        cout << "Insertion Sort" << endl;
    else if (sortFilter(argv[3]) == 2)
        cout << "Bubble Sort" << endl;
    else if (sortFilter(argv[3]) == 3)
        cout << "Shaker Sort" << endl;
    else if (sortFilter(argv[3]) == 4)
        cout << "Shell Sort";
    else if (sortFilter(argv[3]) == 5)
        cout << "Heap Sort" << endl;
    else if (sortFilter(argv[3]) == 6)
    cout << "Merge Sort" << endl;
    else if (sortFilter(argv[3]) == 7)
    cout << "Quick Sort" << endl;
    else if (sortFilter(argv[3]) == 8)
        cout << "Counting Sort" << endl;
    else if (sortFilter(argv[3]) == 9)
        cout << "Radix Sort" << endl;
    else if (sortFilter(argv[3]) == 10)
        cout << "Flash Sort" << endl;
    else
        cout << argv[3] << endl;

    cout << "Input size: " << argv[4] << endl;
    cout << "Input order: ";
    if (orderFilter(argv[5]) == 0)
        cout << "Randomize" << endl;
    else if (orderFilter(argv[5]) == 1)
        cout << "Sorted" << endl;
    else if (orderFilter(argv[5]) == 2)
        cout << "Reversed" << endl;
    else if (orderFilter(argv[5]) == 3)
        cout << "Nearly Sorted" << endl;
    cout << "---------------------------" << endl;
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
    long long count_compare1 = 0, count_compare2 = 0;
    double time_use1 = 0, time_use2 = 0;
    int index1 = sortFilter(argv[2]);
    int index2 = sortFilter(argv[3]);
    timeFunctions[index1](a, n, time_use1);
    cpyArr(a, b, n);
    timeFunctions[index2](a, n, time_use2);
    cpyArr(a, b, n);
    cout << "Runing time: " << time_use1 << "(ms) | " << time_use2 << "(ms)" << endl;

    compFunctions[index1](a, n, count_compare1);
    cpyArr(a, b, n);
    compFunctions[index2](a, n, count_compare2);
    cpyArr(a, b, n);

    cout << "Comparisions: " << count_compare1 << " | " << count_compare2 << endl;
    ofstream out("input.txt");
    if (out.fail())
    {
        cout << "Error opening file" << endl;
        out.close();
    }
    else
    {
        out << n << endl;
        for (int i = 0; i < n; i++)
            out << a[i] << " ";
        out.close();
    }
    delete[] a;
    delete[] b;
}

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "-a") == 0)
    {
        if (strcmp(argv[4], "-both") == 0 || strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-time") == 0)
            command_1(argc, argv);
        else if ((strcmp(argv[4], "-rand") == 0 ) || (strcmp(argv[4], "-rev") == 0) || (strcmp(argv[4], "-nsorted") == 0) || (strcmp(argv[4], "-sorted") == 0))
            command_2(argc, argv);
        else if (atoi(argv[3]) > 0)
            command_3(argc, argv);
        else
            cout << "Wrong input!" << endl;

    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        cout << "COMPARE MODE\n";
        if (argc == 5)
            command_4(argc, argv);
        else if (argc == 6)
            command_5(argc, argv);
        else
            cout << "Wrong input!" << endl;
    }
    else
    {
        cout << "Wrong input!" << endl;
    }

    return 0;
}