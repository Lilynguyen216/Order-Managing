#pragma once
#include <iostream>
using namespace std;

template<class Name>
class queue;

template<class Name>
class Node {
	friend queue<Name>;
private:
	Name data;
	Node* next;
public:
	Node(Name Data);
};

template<class Name>
class queue {
	Node<Name>* Front;
	Node<Name>* Rear;
	int Size;
public:
	queue();
	bool isEmpty();
	void enQueue(Name Data);
	void deQueue();
	Name peek();
	int GetSize();
	void display(ostream& os);
};


template<class Name>
Node<Name>::Node(Name Data) {
	data = Data;
	next = NULL;
}

template<class Name>
queue<Name>::queue() {
	Front = Rear = NULL;
	Size = 0;
}


//kiem tra
template<class Name>
bool queue<Name>::isEmpty() {
	return (Front == NULL);
}

//them vao queue
template<class Name>
void queue<Name>::enQueue(Name Data) {
	Node<Name>* p = new Node<Name>(Data);
	if (p == NULL) {
		return;
	}
	else {
		if (Rear == NULL) {
			Front = Rear = p;
		}
		else {
			Rear->next = p;
			Rear = p;
		}
		Size++;
	}
}

//Xoa phan tu dau ra khoi danh sach
template<class Name>
void queue<Name>::deQueue() {
	if (isEmpty()) {
		return;
	}
	Node<Name>* p = Front;
	Front = p->next;
	delete p;
	Size--;

	if (Front == NULL) {
		Rear = NULL;
	}
}

//lay phann tu dau
template<class Name>
Name queue<Name>::peek() {
	if (isEmpty()) {
		exit;
	}
	return Front->data;
}

//lay kich thuoc
template<class Name>
int queue<Name>::GetSize() {
	return Size;
}

//in ra man hinh
template<class Name>
void queue<Name>::display(ostream& os) {
	for (Node<Name>* p = Front; p != NULL; p = p->next) {
		os << p->data;
		if (p->next != NULL) {
			os << "\n";
		}
	}
}