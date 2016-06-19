#include "SquareSum.h"

int main()
{
	vector<double> Arr;
	string userInput;

	do { 
		cout << "Enter 10 real number (separate by space): \n";
		getline(cin, userInput);
		istringstream iss(userInput);				// extract input separate by spaces
		string temp;
		while (iss >> temp)
			{
				char *p;
				double d = strtod(temp.c_str(), &p);			// convert string to double
				if (*p == 0) {									// if number is double
					Arr.push_back(d);							// push it to array
				}
			}
		if (Arr.size() != 10)						// ensure user type 10 real number exactly
		{
			Arr.clear();							// if not enough, remove all array element
			system("cls");
			cout << "Not enough 10 real number. Try again. \n";
		}
	} while ( Arr.size() != 10);

	// Write 10 number to file
	ofstream outFile("input.txt");					// Create file 'input.txt'
	for (const auto& value : Arr) {
		outFile << value << " ";
	}
	outFile.close();

	// Read number from file and calc sum of square
	ifstream inFile("input.txt");
	if (!inFile.is_open()) {						// file not found or st else
		cout << "Cannot open file.";
		return 0;
	}
	else {
		string line;
		double sumOfSquare = 0.0;
		while (getline(inFile, line))
		{
			istringstream iss(line);
			string temp;
			while (iss >> temp) {
				char *p;
				double d = strtod(temp.c_str(), &p);
				if (isDouble(temp))
					sumOfSquare += pow(d, 2.0);
			}
		}
		cout << "Sum of square: " << sumOfSquare << endl;
	}

	system("pause");
	return 0;
}

/** Check if a number is double */
bool isDouble(const string& str)
{
	char *p;
	strtod(str.c_str(), &p);
	return (*p == 0);
}

