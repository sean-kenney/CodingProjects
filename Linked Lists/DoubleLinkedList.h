#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "LinkedList.h"
#include <ostream>

class DoubleLinkedList : public LinkedList
{
	public:
		DoubleLinkedList() {};
		void removeNode(int key);
		virtual void printList();
		void insertLinkedNode(LinkedNode * node, int data);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);
	private:
		LinkedNode * head_;
		LinkedNode * tail_;
		
};
#endif