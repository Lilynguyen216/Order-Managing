#include "LinkedList.h" 

template <class DataType>
void LinkedList<DataType>::displayNode(Node<DataType>* node) {
	node->display();
}

template <class DataType>
void LinkedList<DataType>::getNode(Node<DataType>* node) {
	node->getData();
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::getHead() {
	return this._pHead;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::getTail() {
	return this._pTail;
}

template <class DataType>
LinkedList<DataType>::LinkedList() {
	_pHead = NULL;
	_pTail = NULL;
	_iSize = 0;
}

template <class DataType>
LinkedList<DataType>::~LinkedList() {}

template <class DataType>
void LinkedList<DataType>::addHead(DataType data) {
	Node<DataType>* pAdd = new Node<DataType>(data);
	if (_pHead == NULL)
	{
		_pHead = _pTail = pAdd;
	}
	else
	{

		pAdd->_pNext = _pHead;
		_pHead = pAdd;
	}
	_iSize++;
}

template <class DataType>
void LinkedList<DataType>::addTail(DataType data)
{
	Node<DataType>* pAdd = new Node<DataType>(data);
	if (_pHead == NULL)
	{
		_pHead = _pTail = pAdd;
	}
	else
	{
		_pTail->_pNext = pAdd;
		_pTail = pAdd;
	}
	_iSize++;
}

template <class DataType>
void LinkedList<DataType>::display() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL)
	{
		pWalker->display();
		pWalker = pWalker->_pNext;
	}
}

template <class DataType>
void LinkedList<DataType>::displayeven() {
	Node<DataType>* pWalker = _pHead;
	while (pWalker != NULL)
	{
		if (pWalker->_data % 2 == 0) {
			pWalker->display();
		}
		pWalker = pWalker->_pNext;
	}
}

template <class DataType>
void LinkedList<DataType>::addAfter(Node<DataType>* node, DataType data)
{
	Node<DataType>* pAdd = new Node<DataType>(data);
	if (node != NULL)
	{
		pAdd->_pNext = node->_pNext;
		node->_pNext = pAdd;
		if (node == _pTail)
			_pTail = pAdd;
	}
	else
	{
		addHead(data);
	}
	_iSize++;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType data)
{
	Node<DataType>* p = _pHead;
	while ((p != NULL) && (p->_data != data))
		p = p->_pNext;
	return p;
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(Node<DataType>* node)
{
	Node<DataType>* p = _pHead;
	if (p == node)
		return NULL;
	while ((p != NULL) && (p->_pNext != node))
		p = p->_pNext;
	return p;
}

template <class DataType>
void LinkedList<DataType>::removeHead() {
	if (_pHead != NULL)
	{
		Node<DataType>* pTemp = _pHead;
		_pHead = _pHead->_pNext;
		delete pTemp;
		if (_pHead == NULL)
			_pTail = NULL;
		_iSize--;
	}
}

template <class DataType>
void LinkedList<DataType>::removeTail()
{
	if (_pHead == NULL)
		return;
	Node<DataType>* pTemp = _pTail;
	_pTail = searchPre(_pTail);
	delete pTemp;
	if (_pTail != NULL)
		_pTail->_pNext = NULL;
	else
		_pHead = NULL;
	_iSize--;
}

template <class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType>* node)
{
	Node<DataType>* pTemp;
	if (node != NULL)
	{
		pTemp = node->_pNext;
		if (pTemp != NULL)
		{
			if (pTemp == _pTail)
				_pTail = node;
			node->_pNext = pTemp->_pNext;
			delete pTemp;
		}
	}
	else
		removeHead();
	_iSize--;
}

template <class DataType>
void LinkedList<DataType>::remove(DataType data)
{
	Node<DataType>* pWalker = _pHead, * pTemp = NULL;
	while ((pWalker != NULL) && (pWalker->_data != data))
	{
		pTemp = pWalker; pWalker = pWalker->_pNext;
	}
	if (pWalker == NULL) return;
	if (pTemp != NULL)
	{
		if (pWalker == _pTail)
		{
			_pTail = pTemp;
			_pTail->_pNext = NULL;
		}
		pTemp->_pNext = pWalker->_pNext;
		delete pWalker;
		_iSize--;
	}
}

template <class DataType>
void LinkedList<DataType>::clear()
{
	while (_pHead != NULL)
		removeHead();
}

template <class DataType>
int LinkedList<DataType>::getSize()
{
	return _iSize;
}

template <class DataType>
void LinkedList<DataType>::selectionSort()
{
	Node<DataType>* pMin;
	Node<DataType>* p, * q;
	for (p = _pHead; p->_pNext != _pTail; p = p->_pNext) {
		pMin = p;
		for (q = p->_pNext; q != _pTail; q = q->_pNext) {
			if (q->_data < pMin->_data)
				pMin = q;
			if (pMin != p)
				swap(p->_data, pMin->_data);
		}
	}
}

template <class DataType>
void LinkedList<DataType>::searchDataAndRemove(DataType data) {
	int i = 0;
	Node<DataType>* p = _pHead;
	while (p->_pNext != NULL && p != _pTail) {
		if (p->_data == data) {
			if (p == _pHead) {
				removeHead();
				break;
			}
			else if (p == _pTail) {
				removeTail();
				break;
			}
			else if (p != _pHead && p != _pTail) {
				Node<DataType>* tmp = searchPre(p);
				removeAfter(tmp);
				break;
			}
		}
		p = p->_pNext;
	}

}

template <class DataType>
void LinkedList<DataType>::searchDataAndAdd(DataType data, DataType datas) {
	Node<DataType>* p = _pHead;
	while (p->_pNext != NULL && p != _pTail) {
		if (p->_data == data) {
			if (p == _pHead) {
				addHead(datas);
				break;
			}
			else
				if (p == _pTail) {
					addTail(datas);
					break;
				}
				else
					if (p != _pHead && p != _pTail) {
						Node<DataType>* tmp = p;
						addAfter(tmp, datas);
						break;
					}
		}
		p = p->_pNext;
	}
}

template <class DataType>
Node<DataType>* LinkedList<DataType>::getNode(int index) {
	Node<DataType>* pTemp = _pHead;
	int i = 0;
	while (pTemp != NULL && i != index) {
		pTemp = pTemp->_pNext;
		i++;
	}
	if (i == index && pTemp != NULL)
		return pTemp;
	return NULL;
}
