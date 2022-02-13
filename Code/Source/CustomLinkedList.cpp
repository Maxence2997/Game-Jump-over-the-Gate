#include <iostream>
#include "CustomLinkedList.h"
#include "NodeT.h"
#include "Cards.h"
using namespace std;

template class CustomLinkedList<Card>;
template class CustomLinkedList<int>;
/*============================PRIVATE============================*/
template <typename K>
void CustomLinkedList<K>::connect(Node<K>* left, Node<K>* right) {

	left->setNext(right);
	right->setPrev(left);
}

template <typename K>
void CustomLinkedList<K>::add(Node<K>* next)	//add it at the tail of List
{
	if (head == nullptr)						//if the list is currently empty
	{
		head = next;
		tail = head;
	}
	else										//if is not empty, then add to the end and move the tail
	{
		connect(tail, next);					//connect tail with the next node
		flag = false;							//disconnecion of the circular link

		connect(next, head);					//connect the next node with head
		flag = true;							//connecion of the circular link

		tail = next;							//move tail to the next node
	}

	count++;
}

template <typename K>
void CustomLinkedList<K>::add(int index, Node<K>* next) {

	if (index<0 && index>(count - 1))

		throw "Out of bound of the list.";

	else
	{
		if (index == count - 1)						//add at the tail
			add(next);

		else if (index == 0)						//add at the head
		{
			connect(tail, next);					//connect tail with the next node
			flag = false;							//disconnecion of the circular link

			connect(next, head);					//connect the next node with head
			flag = true;							//connecion of the circular link

			head = next;							//move head to the next node
		}
		else
		{
			Node<K>* cursor = head;

			for (int i = 0; i < index; i++)
				cursor = cursor->getNext();			//move the cursor

			Node<K>* prev = cursor->getPrev();

			connect(prev, next);					//connect prevouis node with the next node
			flag = false;							//disconnecion of the circular link

			connect(next, cursor);					//connect the next node with cursor node
			flag = true;							//connecion of the circular link
		}
		count++;
	}
}

/*============================PUBLIC============================*/
template <typename K>   
CustomLinkedList<K>::CustomLinkedList()  //constructor
{
	head = nullptr;
	tail = nullptr;
	flag = false;
	count = 0;
}

template <typename K>
CustomLinkedList<K>:: ~CustomLinkedList()
{
	Node<K>* cursor = head;

	for (int i = 0; i < count; i++)
	{
		Node<K>* toRemove = cursor;
		cursor = cursor->getNext();
		delete toRemove;
	}
}



template <typename K>
void CustomLinkedList<K>::add(K& val)			//add it at the tail of List
{
	Node<K>* next = new Node<K>(val);

	if (head == nullptr)						//if the list is currently empty
	{
		head = next;
		tail = head;
	}
	else										//if is not empty, then add to the end and move the tail
	{
		connect(tail, next);					//connect tail with the next node
		flag = false;							//disconnecion of the circular link

		connect(next, head);					//connect the next node with head
		flag = true;							//connecion of the circular link

		tail = next;							//move tail to the next node
	}
	count++;
}

template <typename K>
void CustomLinkedList<K>::add(K* val)			//add it at the tail of List
{
	Node<K>* next = new Node<K>(*val);

	if (head == nullptr)						//if the list is currently empty
	{
		head = next;
		tail = head;
	}
	else										//if is not empty, then add to the end and move the tail
	{
		connect(tail, next);					//connect tail with the next node
		flag = false;							//disconnecion of the circular link

		connect(next, head);					//connect the next node with head
		flag = true;							//connecion of the circular link

		tail = next;							//move tail to the next node
	}
	count++;
}




template <typename K>
void CustomLinkedList<K>::add(int index, K& val) {

	if (index<0 && index>(count - 1))

		throw "Out of bound of the list.";

	else
	{
		Node<K>* next = new Node<K>(val);

		if (index == count - 1)						//add at the tail
			add(next);

		else if (index == 0)						//add at the head
		{
			connect(tail, next);					//connect tail with the next node
			flag = false;							//disconnecion of the circular link

			connect(next, head);					//connect the next node with head
			flag = true;							//connecion of the circular link

			head = next;							//move head to the next node
		}
		else
		{
			Node<K>* cursor = head;

			for (int i = 0; i < index; i++)
				cursor = cursor->getNext();			//move the cursor

			Node<K>* prev = cursor->getPrev();

			connect(prev, next);					//connect prevouis node with the next node
			flag = false;							//disconnecion of the circular link

			connect(next, cursor);					//connect the next node with cursor node
			flag = true;							//connecion of the circular link
		}
		count++;
	}
}

template <typename K>
void CustomLinkedList<K>::add(int index, K* val) {

	if (index<0 && index>(count - 1))

		throw "Out of bound of the list.";

	else
	{
		Node<K>* next = new Node<K>(*val);

		if (index == count - 1)						//add at the tail
			add(next);

		else if (index == 0)						//add at the head
		{
			connect(tail, next);					//connect tail with the next node
			flag = false;							//disconnecion of the circular link

			connect(next, head);					//connect the next node with head
			flag = true;							//connecion of the circular link

			head = next;							//move head to the next node
		}
		else
		{
			Node<K>* cursor = head;

			for (int i = 0; i < index; i++)
				cursor = cursor->getNext();			//move the cursor

			Node<K>* prev = cursor->getPrev();

			connect(prev, next);					//connect prevouis node with the next node
			flag = false;							//disconnecion of the circular link

			connect(next, cursor);					//connect the next node with cursor node
			flag = true;							//connecion of the circular link
		}
		count++;
	}
}

template <typename K>
void CustomLinkedList<K>::remove() {

	Node<K>* prev = tail->getPrev();
	Node<K>* toRemove = tail;

	connect(prev, head);						//connect prevouis node with head node
	flag = true;								//connecion of the circular link

	tail = prev;								//move tail ptr

	delete toRemove;							//delete the node

	count--;
}

template <typename K>
void CustomLinkedList<K>::remove(int index) {

	if (index<0 && index>(count - 1))

		throw "Out of bound of the list.";

	else
	{
		if (index == count - 1)						//remove at the tail
			remove();

		else if (index == 0)						//remove at the head
		{
			Node<K>* second = head->getNext();
			Node<K>* toRemove = head;

			connect(tail, second);					//connect tail with the next node of head
			flag = true;							//disconnecion of the circular link

			head = second;							//move head to the next node of the head
			delete toRemove;
		}
		else
		{
			Node<K>* cursor = head;

			for (int i = 0; i < index; i++)
				cursor = cursor->getNext();			//move the cursor

			Node<K>* prev = cursor->getPrev();
			Node<K>* next = cursor->getNext();
			connect(prev, next);					//connect prevouis node with the next node
			flag = true;							//disconnecion of the circular link

			delete cursor;
		}
		count--;
	}
}

template <typename K>
int CustomLinkedList<K>::find(K object) {

	int flag = -1;
	Node<K>* cursor = head;

	for (int i = 0; i < count; i++)
	{

		K val = cursor->getValue();

		if (object == val)
		{
			flag = i;								//i for index
			break;
		}
		cursor = cursor->getNext();
	}
	return flag;									//return index or -1 which representes not found
}

template <typename K>
K& CustomLinkedList<K>::get(int index) {

	if (index<0 && index>(count - 1))

		throw "Out of bound of the list.";

	else
	{
		Node<K>* cursor = head;
		K& val = head->getValue();
		for (int i = 0; i < count; i++) 			//i for index
		{

			if (index == i)
			{
				val = cursor->getValue();
				break;
			}
			cursor = cursor->getNext();
		}
		return val;
	}
}

template <typename K>
int CustomLinkedList<K>::sizeOf() {

	return count;
}

template <typename K>
void CustomLinkedList<K>::printList() {

	if (count <= 0)

		throw "The list is empty.";

	else
	{
		Node<K>* cursor = head;

		for (int i = 0; i < count; i++) 			//i for index
		{
			K val = cursor->getValue();
			cout << val << endl;
			cursor = cursor->getNext();
		}
	}
}


