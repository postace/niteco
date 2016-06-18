#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

/** find max of sequence */
int findMax(vector<int> arr);

/** find min of sequence */
int findMin(vector<int> arr);

/** Find number has largest frequent existence, using map */
void findMaxFreq(vector<int> arr);

/** Sort Array, using Bubble Sort */
void sortArray(vector<int> &arr, bool asc);

/** Check if a string is integer
* return true if string contain number, false otherwise
*/
bool isNumber(const string& str);

/** Print array to screen */
void printArray(vector<int> arr);


