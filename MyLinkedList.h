

#include <string>
using std::string;


/* class implementation in the cpp file*/
class Node;
/* implenets LinkedList that each element is Node as explined in the assignment*/
class MyLinkedList{
private:

	/* pointer of head node */
	Node *_pHead;
	/* pointer of tail node */
	Node *_pTail;

	size_t _size;

public:
	/* Constructors with No Arguments */
	MyLinkedList(void);
	/*constractor that builds MyLinkedList from string and double arrays*/
	MyLinkedList(string keys[],double values[],size_t size);
	/*copy constructor*/
	MyLinkedList(const MyLinkedList &other);
	/* Destructor */
	~MyLinkedList(void);
	/* assign operator*/
	MyLinkedList& operator=(const MyLinkedList& other);
	/* equal operator between two MyLinkedList*/
	bool operator==(const MyLinkedList& other)const;
	/*NOT equal operator between two MyLinkedList*/
	bool operator!=(const MyLinkedList& other)const;
	/* return true if there is an element such (key,data), false otherwise*/
	bool isInList(string key,double data);
	/* summing up the data for each element*/
	double sumList();
	/* return how many elements in the list right now*/
	size_t size() const;
	/* Function to append a node to the end of a linked list */
	void add(string key,double data);
	/*delete the list elements*/
	void clear();
	/* copy the elements in other to "this" */
	void copy(const MyLinkedList &other);
	/* remove function as explined in the assignmen */
	size_t remove(string key);

};
