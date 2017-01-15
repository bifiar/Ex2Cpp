
#include "MyLinkedList.h"

/*defenition of class Node*/
class Node
{
	friend class MyLinkedList;

private:
	double _data; /* data, can be any data type, but use integer for easiness */
	string _key;
	Node *_pNext; /* pointer to the next node */
	Node *_pPrev;

	/* Constructors with No Arguments */
	Node(void)
	: _pNext(NULL),_pPrev(NULL)
	{ }

	~Node(void)	{}
	/* Constructors with a given data*/
	Node(string key,double data)
	: _data(data),_key(key), _pNext(NULL),_pPrev(NULL)
	{ }

	/* Constructors with a given dataue and a link of the next node */
	Node(string key,double data, Node* next,Node* prev)
	: _data(data),_key(key), _pNext(next),_pPrev(prev)
	{}

	/* Getters */
	double getdataue(void)
	{ return _data; }
	string getKey(void)
	{return _key;}

	Node* getNext(void)
	{ return _pNext; }

	Node* getPrev(void)
	{ return _pPrev; }
};
/* definition of the linked list class */

MyLinkedList::MyLinkedList()
:_pHead(NULL),_pTail(NULL),_size(0){}

// understanding intilization list-------------------------------------
MyLinkedList::MyLinkedList(string keys[],double values[],size_t size)
:_pHead(NULL),_pTail(NULL),_size(0)
{
	size_t i;
	for (i = 0; i < size; i++) {
		add(keys[i],values[i]);
	}
}

MyLinkedList::MyLinkedList(const MyLinkedList &other)
/* copy constructor*/
:_pHead(NULL),_pTail(NULL),_size(0)
{
	copy(other);
}
MyLinkedList::~MyLinkedList()
{
	clear();
}
void MyLinkedList:: copy(const MyLinkedList &other){
	Node* current = other._pHead;
	while(current!=NULL){
		add(current->_key, current->_data);
		current  = current->_pNext;
	}
}
void MyLinkedList:: clear(){
	Node *pDel = _pHead;

	/* Traverse the list and delete the node one by one from the head */
	while (pDel != NULL) {
		/* take out the head node */
		_pHead = _pHead->_pNext;
		delete pDel;
		/* update the head node */
		pDel = _pHead;
	}
	/* Reset the head and tail node */
	_pTail = _pHead = NULL;
	_size = 0;
}


MyLinkedList& MyLinkedList::operator=(const MyLinkedList& other)
{
	if (this!=&other) {
		clear();
		copy(other);
	}
	return *this;
}

bool MyLinkedList::operator==(const MyLinkedList& other)const
		{
	Node* current;
	const  Node* currentO;
	size_t i;
	currentO=other._pHead;
	current=_pHead;
	if(_size!=other.size())
	{
		return false;
	}
	for (i = 0; i < _size; i++) {
		if((current->_data!=currentO->_data)||(current->_key!=currentO->_key))
		{
			return false;
		}
		current= current->_pNext;
		currentO= currentO->_pNext;
	}
	return true;
		}
bool MyLinkedList::operator!=(const MyLinkedList& other)const
		{
	// TODO check
	return !(other==*this);
		}
void MyLinkedList::add(string key,double data)
{
	/* The list is empty? */
	if (_pHead == NULL) {
		/* the same to create a new list with a given dataue */

		_pTail = _pHead = new Node(key,data);

	}
	else
	{
		/* Append the new node to the tail */
		_pTail->_pNext = new Node(key,data);
		/* Update the tail pointer */
		_pTail->_pNext->_pPrev = _pTail;
		_pTail = _pTail->_pNext;
		_pTail->_pNext = _pHead; // cycling
	}
	_size++;
}

size_t  MyLinkedList::remove(string key){
	Node *pCurrent = _pHead;
	size_t  count = 0;
	while(pCurrent!=NULL){
		if((pCurrent->_key==key)){
			count++;
			if(_pHead == _pTail){// if there is only one element in the list
				_pHead = _pTail =  NULL;
				delete pCurrent;
				pCurrent = NULL;
			}
			else if(pCurrent == _pTail){ // if it's the last element
				_pTail = _pTail->_pPrev;
				_pTail->_pNext = NULL;
				delete pCurrent;
				pCurrent = NULL;
			}
			else if(pCurrent == _pHead){// if it's the first element
				_pHead = _pHead->_pNext;
				_pHead->_pPrev = NULL;
				delete pCurrent;
				pCurrent = _pHead;
			}
			else{ // otherwise:
				Node *temp = pCurrent;
				pCurrent->_pPrev->_pNext = pCurrent->_pNext;
				pCurrent->_pNext->_pPrev = pCurrent->_pPrev;
				pCurrent = temp->_pNext;
				delete temp;

			}
		}
		else{ // premoting current
			pCurrent = pCurrent->_pNext;
		}

	}
	_size-=count;
	return count;
}




bool MyLinkedList::isInList(string key, double data)
{
	Node* current=_pHead;
	while(current!=NULL)
	{
		if(current->_key==key&&current->_data==data)
		{
			return true;
		}
		current=current->_pNext;
	}
	return false;
}
double MyLinkedList::sumList()
{
	double sum=0;
	Node* current=_pHead;
	while(current!=NULL)
	{
		sum+=current->_data;
		current=current->_pNext;
	}
	return sum;
}
size_t MyLinkedList::size() const
{
	return _size;
}



