#include "s/sorts.cpp"
#include "DataGenerator.cpp"

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

int main(int argc, char **argv)
{
	cout << "ALGORITHM MODE" << endl;
	int nums = 0;
	int* arr = NULL;
	for (int i = 2; i < argc; i++)
	{
		if (i == 2)
			cout << "Algorithm: " << argv[i] << endl;
		if (i == 3)
		{
			cout << "Input file: " << argv[i] << endl;
			ifstream ifs(argv[i]);
			if (ifs.fail())
			{
				cout << "Error opening file" << endl;
				return 0;
			}
			else
			{
				ifs >> nums;
				arr = new int[nums];
				// int dataType;
				// cout << "Nhap dataType (0: random, 1: sorted, 2: reverse, 3: nearly sorted): ";
				// cin >> dataType;
				// if (dataType < 0 || dataType > 3)
				// {
				// 	cout << "Error: unknown data type!\n";
				// 	return 0;
				// }
				// GenerateData(arr, nums, dataType);
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
				// selectionSort,
				shakerSort,
				shellSort,
				radixSort,
			};
			sortWithTime timeFunctions[] =
			{
				// selectionSort_noComp,
				shakerSort_noComp,
				shellSort_noComp,
				radixSort_noComp,
			};
			// check function
			int index = sortFilter(argv[2]);
			if (index == -1)
			{
				cout << "Error: Unknown sort type!\n";
				return 0;
			}
			// Mode
			if (!strcmp(argv[4], "-both") || !strcmp(argv[4], "-comp"))
				compFunctions[index](arr, nums, count_compare);

			timeFunctions[index](arr, nums, time_use);

			if (!strcmp(argv[4], "-both"))
			{
				cout << "Comparisons: " << count_compare << endl;
				cout << "Running time: " << time_use << " milliseconds" << endl;
			}
			else if (!strcmp(argv[4], "-comp"))
				cout << "Comparisons: " << count_compare << endl;
			else if (!strcmp(argv[4], "-time"))
				cout << "Running time: " << time_use << " milliseconds" << endl;

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
	return 0;
}
// command_1.exe -a radix-sort input.txt -both