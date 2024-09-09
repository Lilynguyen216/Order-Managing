#pragma once
#ifndef Node_H
#define Node_H
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
using namespace std;

template <class DataType>
class LinkedList;

template <class DataType>
class Node {
	friend LinkedList<DataType>;
private:
	DataType _data; 
	Node* _pNext;
public:
	DataType getData();
	void setData(DataType data);
	Node* getpNext();
	Node(DataType data);
	Node* operator=(const Node* other); // Assignment operator
	bool operator!=(const Node& other) const; // Not equal operator
	void display();
};

#endif // !Node_H
