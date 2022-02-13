#ifndef NODE_H
#define NODE_H

template <typename T> 

/*	@Author: Maxence2997
	@Version:1.0
	@Date: 2022/02/04		*/

class Node {

private:

	Node<T>* prev;
	Node<T>* next;
	T value;

public:

	Node<T>();
	Node<T>(T& info);
	~Node<T>();

	void setNext(Node<T>* nextOne);
	Node<T>* getNext();
	bool hasNext();
	
	void setPrev(Node<T>* pre);
	Node<T>* getPrev();
	bool hasPrev();
	
	T& getValue();
	void setValue(T& val);
};
#endif

