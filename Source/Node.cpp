#include "Node.h"

template<class DataType>
DataType Node<DataType>::getData() {
	return _data;
}

template<class DataType>
void Node<DataType>::setData(DataType data) {
	_data = data;
}

template <class DataType>
Node<DataType>* Node<DataType>::getpNext() {
	return _pNext;
}

template<class DataType>
Node<DataType>::Node(DataType data) {
	_data = data;
	_pNext = NULL;
}

template<class DataType>
void Node<DataType>::display() {
	cout << _data << endl;
}

// Assignment operator
template<class DataType>
Node<DataType>* Node<DataType>::operator=(const Node<DataType>* other) {
	this->_data = other->_data;
	this->_pNext = other->_pNext; 
	return this;
}

// Not equal operator
template<class DataType>
bool Node<DataType>::operator!=(const Node<DataType>& other) const {
	return this->_data != other._data || this->_pNext != other._pNext;
}
