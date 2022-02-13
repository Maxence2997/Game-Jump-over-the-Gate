#ifndef CUSTOMLINKEDLIST_H
#define CUSTOMLINKEDLIST_H
#include "NodeT.h"

/*	@Author: Maxence2997
	@Version:1.0
	@Date: 2022/02/04		*/


template <typename K>
class CustomLinkedList {

private:
	Node<K>* head, * tail;
	bool flag;									//circular flag
	int count;
	void connect(Node<K>* left, Node<K>* right);
	void add(int index, Node<K>* next);			//add it by index based on ZERO	
	void add(Node<K>* next);					//add it at the tail of List

public:
	CustomLinkedList();
	~CustomLinkedList();
	void add(K& val);
	void add(K* val);					
	void add(int index, K& val);
	void add(int index, K* val);
	void remove();								//remove the last one
	void remove(int index);						//remove by the index based on ZERO										
	int find(K object);
	K& get(int index);
	int sizeOf();
	void printList();

};



#endif
