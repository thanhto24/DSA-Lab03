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

void printNameSort(int index)
{
    if (index == 0)
        cout << "Selection Sort";
    else if (index == 1)
        cout << "Insertion Sort";
    else if (index == 2)
        cout << "Bubble Sort";
    else if (index == 3)
        cout << "Shaker Sort";
    else if (index == 4)
        cout << "Shell Sort";
    else if (index == 5)
        cout << "Heap Sort";
    else if (index == 6)
        cout << "Merge Sort";
    else if (index == 7)
        cout << "Quick Sort";
    else if (index == 8)
        cout << "Counting Sort";
    else if (index == 9)
        cout << "Radix Sort";
    else if (index == 10)
        cout << "Flash Sort";
    else
        cout << "Unknown Sorting Algorithm!";
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

void printTypeOrder(int index)
{
    cout << "Input order: ";
    if (index == 0)
        cout << "Randomize" << endl;
    else if (index == 1)
        cout << "Sorted" << endl;
    else if (index == 2)
        cout << "Reversed" << endl;
    else if (index == 3)
        cout << "Nearly Sorted" << endl;
}

void cpyArr(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

bool checkError(int index, int type)
{
    if (index == -1)
    {
        if (type == 1)
            cout << "Error: Unknown sort type!\n";
        else
            cout << "Error: unknown data type!\n";
        return false;
    }
    return true;
}

bool isNum(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

void command_1(int argc, char **argv, sortWithComp compFunctions[], sortWithTime timeFunctions[])
{
    int nums = 0;
    int *arr = NULL;
    for (int i = 2; i < argc; i++)
    {
        if (i == 2)
        {
            cout << "ALGORITHM MODE: " << endl;
            cout << "Algorithm : ";
            printNameSort(sortFilter(argv[i]));
            cout << endl;
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
                if (nums <= 0)
                {
                    cout << "Error: input size must be a positive number!";
                    ifs.close();
                    return;
                }
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

            // check function
            int index = sortFilter(argv[2]);
            if (!checkError(index, 1))
                return;
            // Mode
            if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
                compFunctions[index](arr, nums, count_compare);

            timeFunctions[index](arr, nums, time_use);

            if (!strcmp(argv[4], "-both"))
            {
                cout << "---------------------------" << endl;
                cout << "Running time (if required): " << time_use << " (s)" << endl;
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
                cout << "Running time (if required): " << time_use << " (s)" << endl;
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

void command_2(int argc, char **argv, sortWithComp compFunctions[], sortWithTime timeFunctions[])
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
                printNameSort(sortFilter(argv[i]));
                cout << endl;
            }
            if (i == 3)
            {
                cout << "Input size : " << argv[i] << endl;
                nums = atoi(argv[i]);
                if (nums <= 0)
                {
                    cout << "Error: input size must be a positive number!";
                    return;
                }
            }
            if (i == 4)
            {
                printTypeOrder(orderFilter(argv[i]));
                long long count_compare = 0;
                int *arr = new int[nums];
                double time_use = 0;
                int dataType = 0;

                dataType = orderFilter(argv[i]);
                if (!checkError(dataType, 2))
                    return;

                GenerateData(arr, nums, dataType);

                // check function
                int index = sortFilter(argv[2]);
                if (!checkError(index, 1))
                    return;
                // Mode
                if (!strcmp(argv[5], "-both") || !strcmp(argv[5], "-comp"))
                    compFunctions[index](arr, nums, count_compare);

                timeFunctions[index](arr, nums, time_use);

                if (!strcmp(argv[5], "-both"))
                {
                    cout << "---------------------------" << endl;
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
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
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
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

void command_3(int argc, char **argv, sortWithComp compFunctions[], sortWithTime timeFunctions[])
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
                printNameSort(sortFilter(argv[i]));
                cout << endl;
            }
            if (i == 3)
            {
                cout << "Input size: " << argv[i] << endl;
                nums = atoi(argv[i]);
                if (nums <= 0)
                {
                    cout << "Error: input size must be a positive number!";
                    return;
                }
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

                if (!checkError(index, 2))
                    return;

                cout << "\nInput order: Randomize" << endl;
                cout << "---------------------------" << endl;
                dataType = 0;
                GenerateData(arr_1, nums, dataType);

                if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
                    compFunctions[index](arr_1, nums, count_compare);
                timeFunctions[index](arr_1, nums, time_use);

                if (!strcmp(argv[4], "-both"))
                {
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                else
                {
                    cout << "Wrong input!";
                    return;
                }
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
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                else
                {
                    cout << "Wrong input!";
                    return;
                }
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
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                else
                {
                    cout << "Wrong input!";
                    return;
                }
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
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                    cout << "Comparisons  (if required): " << count_compare << endl;
                }
                else if (!strcmp(argv[4], "-comp"))
                    cout << "Comparisons  (if required): " << count_compare << endl;
                else if (!strcmp(argv[4], "-time"))
                    cout << "Running time (if required): " << time_use << " (s)" << endl;
                else
                {
                    cout << "Wrong input!";
                    return;
                }
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

void command_4(int argc, char **argv, sortWithComp compFunctions[], sortWithTime timeFunctions[])
{
    int n;
    ifstream fin(argv[4]);
    if (!fin)
        return;
    fin >> n;
    if (n <= 0)
    {
        cout << "Error: input size must be a positive number!";
        fin.close();
        return;
    }
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];
    fin.close();
    int *b = new int[n];
    cpyArr(b, a, n);
    cout << "COMPARE MODE\n";
    cout << "Algorithm: ";
    printNameSort(sortFilter(argv[2]));
    cout << " | ";
    printNameSort(sortFilter(argv[3]));
    cout << endl;
    cout << "Input file: " << argv[4] << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------" << endl;

    // check function
    long long count_compare1 = 0, count_compare2 = 0;
    double time_use1 = 0, time_use2 = 0;
    int index1 = sortFilter(argv[2]);
    int index2 = sortFilter(argv[3]);
    timeFunctions[index1](a, n, time_use1);
    cpyArr(a, b, n);
    timeFunctions[index2](a, n, time_use2);
    cpyArr(a, b, n);
    cout << "Runing time: " << time_use1 << "(s) | " << time_use2 << "(s)" << endl;

    compFunctions[index1](a, n, count_compare1);
    cpyArr(a, b, n);
    compFunctions[index2](a, n, count_compare2);
    cpyArr(a, b, n);

    cout << "Comparisions: " << count_compare1 << " | " << count_compare2 << endl;

    delete[] a;
    delete[] b;
}

void command_5(int argc, char **argv, sortWithComp compFunctions[], sortWithTime timeFunctions[])
{
    if (!checkError(sortFilter(argv[2]), 1) || !checkError(sortFilter(argv[3]), 1) || !checkError(orderFilter(argv[5]), 2))
        return;
    int n;
    n = atoi(argv[4]);
    if (n <= 0)
    {
        cout << "Error: input size must be a positive number!";
        return;
    }
    int *a = new int[n];
    GenerateData(a, n, orderFilter(argv[5]));
    int *b = new int[n];
    cpyArr(b, a, n);
    cout << "COMPARE MODE\n";
    cout << "Algorithm: ";
    printNameSort(sortFilter(argv[2]));
    cout << " | ";
    printNameSort(sortFilter(argv[3]));
    cout << endl;
    cout << "Input size: " << n << endl;
    printTypeOrder(orderFilter(argv[5]));
    cout << "---------------------------" << endl;

    long long count_compare1 = 0, count_compare2 = 0;
    double time_use1 = 0, time_use2 = 0;
    int index1 = sortFilter(argv[2]);
    int index2 = sortFilter(argv[3]);
    timeFunctions[index1](a, n, time_use1);
    cpyArr(a, b, n);
    timeFunctions[index2](a, n, time_use2);
    cpyArr(a, b, n);
    cout << "Runing time: " << time_use1 << "(s) | " << time_use2 << "(s)" << endl;

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
    if (strcmp(argv[1], "-a") == 0)
    {
        if (argc == 5 && ((strcmp(argv[4], "-time") == 0) || (strcmp(argv[4], "-comp") == 0) || (strcmp(argv[4], "-both") == 0)))
        {
            if (!isNum(argv[3]))
                command_1(argc, argv, compFunctions, timeFunctions);
            else
                command_3(argc, argv, compFunctions, timeFunctions);
        }
        else if (argc == 6 && (strcmp(argv[4], "-rand") == 0) || (strcmp(argv[4], "-rev") == 0) || (strcmp(argv[4], "-nsorted") == 0) || (strcmp(argv[4], "-sorted") == 0))
            command_2(argc, argv, compFunctions, timeFunctions);
        else
            cout << "Wrong input!" << endl;
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        if (argc == 5)
            command_4(argc, argv, compFunctions, timeFunctions);
        else if (argc == 6)
            command_5(argc, argv, compFunctions, timeFunctions);
        else
            cout << "Wrong input!" << endl;
    }
    else
    {
        cout << "Wrong input!" << endl;
    }

    return 0;
}