#include "DoubleLinkedList.h"

void DoubleLinkedList::removeNode(int key)
{
	// Case #1
	if(key == head_->getData())
	{
		if(head_->hasNextLinkedNode())
		{
			LinkedNode * currentHead = head_;
			LinkedNode * nextNode = head_->getNextLinkedNode();
			head_ = nextNode;
			nextNode->setPrevLinkedNode(nullptr);
			currentHead->setNextLinkedNode(nullptr);
			delete currentHead;
		}
		else
		{
			LinkedNode * currentHead = head_;
			head_ = nullptr;
			tail_ = nullptr;
			delete currentHead;
		}
		
	}
	else if(key == tail_->getData())
	{
		if(tail_->hasPrevLinkedNode())
		{
			LinkedNode * currentTail = tail_;
			LinkedNode * previousNode = tail_->getPrevLinkedNode();
			tail_ = previousNode;
			previousNode->setNextLinkedNode(nullptr);
			currentTail->setPrevLinkedNode(nullptr);
			delete currentTail;
		}
	}
	else
	{
		LinkedNode * currentNode = head_;
		bool isFound = false;
		while(currentNode->hasNextLinkedNode() && !isFound)
		{
			currentNode = currentNode->getNextLinkedNode();
			if(currentNode->getData() == key)
			{
				isFound = true;
			}
		}
		
		if(isFound)
		{
			currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
			currentNode->getNextLinkedNode()->setPrevLinkedNode(currentNode->getPrevLinkedNode());
			currentNode->setNextLinkedNode(nullptr);
			currentNode->setPrevLinkedNode(nullptr);
			delete currentNode;
		}
		else
		{
			std::cout << "Key not found bozo" << std::endl;
		}
	}
}

/*
virtual void DoubleLinkedList::printList()
{
	
}
*/

void DoubleLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	
}

void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{

}

void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	
}
