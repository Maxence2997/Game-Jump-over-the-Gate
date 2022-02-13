#include <string>
#include<vector>
#include <algorithm>
#include "Lib.h"
using namespace std;

int& toReference(int* pointer) {
	return *pointer;
}



 /*template <typename T>
size_t getArrayIndex(vector<T> words, T obj) {

	size_t index = distance(words.begin(), find(words.begin(), words.end(), obj));
	return index;
}
template size_t getArrayIndex(vector<string> words, string obj);*/

size_t getArrayIndex(vector<string> words, string obj)
{
	size_t index = distance(words.begin(), find(words.begin(), words.end(), obj));
	return index;
}

bool isNumeric(string str) {

	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false; //when one non numeric value is found, return false

	return true;
}
