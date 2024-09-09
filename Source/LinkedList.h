#pragma once
#ifndef Linked_List_H
#define Linked_List_H
#include "Node.h"

template <class DataType>
class LinkedList {
	int _iSize;
	Node<DataType>* _pHead;
	Node<DataType>* _pTail;
public:
	LinkedList();
	~LinkedList();
	void addHead(DataType data);
	void addTail(DataType data);
	void addAfter(Node<DataType>* node, DataType data);
	Node<DataType>* search(DataType data);
	Node<DataType>* searchPre(Node<DataType>* node);
	void removeHead();
	void removeTail();
	void removeAfter(Node<DataType>* node);
	void remove(DataType data);
	void clear();
	void selectionSort();
	int getSize();
	void display();
	void displayeven();
	void displayNode(Node<DataType>* node);
	void getNode(Node<DataType>* node);
	Node<DataType>* getHead();
	Node<DataType>* getTail();
	void searchDataAndRemove(DataType data);
	void searchDataAndAdd(DataType data, DataType datas);
	Node<DataType>* getNode(int index);
};

#endif // !Linked_List_H
