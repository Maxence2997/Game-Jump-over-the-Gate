#include "Lib.h"
#include "NodeT.h"
#include "Cards.h"

template class Node<Card>;
template class Node<int>;

template <typename T>
Node<T>::Node(T& val) {

	prev = nullptr;
	value = val;
	next = nullptr;
}

template <typename T>
Node<T>::Node() {

}

template <typename T>
Node<T>::~Node() {

	/*if (this->hasNext())
		getNext()->setPrev(nullptr);

	if (this->hasPrev())
		getPrev()->setNext(nullptr);*/
}

template <typename T>
void Node<T>::setNext(Node<T>* nextOne) {

	next = nextOne;
}

template <typename T>
Node<T>* Node<T>::getNext() {

	return next;
}

template <typename T>
bool Node<T>::hasNext() {

	bool flag = false;

	if (next != nullptr)
		flag = true;

	return flag;
}

template <typename T>
void Node<T>::setPrev(Node<T>* pre) {

	prev = pre;
}

template <typename T>
Node<T>* Node<T>::getPrev() {

	return prev;
}

template <typename T>
bool Node<T>::hasPrev() {

	bool flag = false;

	if (prev != nullptr)
		flag = true;

	return flag;
}

template <typename T>
T& Node<T>::getValue() {

	return value;
}

template <typename T>
void Node<T>::setValue(T& val) {

	value = val;
}


