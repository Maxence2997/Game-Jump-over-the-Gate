#ifndef LIB_H
#define LIB_H
#include <string>
#include <vector>
using namespace std;

int& toReference(int* pointer);

//template <typename T> inline
//size_t getArrayIndex(vector<T> words, T obj) ;

size_t getArrayIndex(vector<string> words, string obj);
bool isNumeric(string str);

#endif // ! LIB_H

