#include "main.h"

int main()
{
	vector<int> Arr;
	string userInput;

	cout << "Enter sequence number(separate by space, 'enter' to exit): \n";

	getline(cin, userInput);
	istringstream iss(userInput);			// extract numbers from user input
	string temp;
	while (iss >> temp)
	{
		if (isNumber(temp))					// if string is number
			Arr.push_back(stoi(temp));		// convert it and push to array
	}
	printArray(Arr);
	cout << "Max is: " << findMax(Arr) << endl;
	cout << "Min is: " << findMin(Arr) << endl;
	cout << "Sort Ascending: \n";
	sortArray(Arr, true);
	cout << "Sort Descending: \n";;
	sortArray(Arr, false);
	findMaxFreq(Arr);
	system("pause");
	return 0;
}

int findMax(vector<int> arr)
{
	int max = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

int findMin(vector<int> arr)
{
	int min = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}

void findMaxFreq(vector<int> arr)
{
	map<int, int> m;
	int currentMax = -999;					// represents invalid number
	int maxCount = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int updated = m[arr[i]]++;			// Increment value of key for counting occurances
		updated++;							// due to post increment
		if (maxCount < updated)
		{
			maxCount = updated;
			currentMax = arr[i];
		}
	}
	cout << "\nMost Freq: " << currentMax << " (" << maxCount << " times). \n";
}

void sortArray(vector<int> &arr, bool asc)
{
	int leng = arr.size();
	for (int i = 0; i < leng; i++)
	{
		for (int j = 0; j < leng - i - 1; j++)
		{
			if (asc) {								// sort array ascending
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			} else {								// sort array descending
				if (arr[j] < arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	printArray(arr);
}

bool isNumber(const string& str)
{
	char* p;
	strtol(str.c_str(), &p, 10);
	return !(*p);
}

void printArray(vector<int> arr)
{
	cout << "\nCurrent Array: ";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

