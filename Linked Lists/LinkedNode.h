#ifndef LINKED_NODE_H
#define LINKED_NODE_H
#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode() {}
		LinkedNode(int data);
		LinkedNode(int data, LinkedNode * nextNode);
		LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode);
		virtual ~LinkedNode();
		LinkedNode * getNextLinkedNode();
		void setNextLinkedNode(LinkedNode * nextNode);
		bool hasNextLinkedNode();
		LinkedNode * getPrevLinkedNode();
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		bool hasPrevLinkedNode();
	private:
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
};
#endif