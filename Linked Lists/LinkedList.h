#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedNode.h"
#include "Node.h"
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		
		LinkedNode * getHead();
		LinkedNode * getTail();
		void setHead(LinkedNode * head);
		void setTail(LinkedNode * tail);
		
		bool isEmpty();
		int getLength();
		void insert(int element);
		void printList();
		void removeNode(int key);
	private:
		LinkedNode * head_;
		LinkedNode * tail_;
};
#endif