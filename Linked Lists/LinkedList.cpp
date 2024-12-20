#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr)
{
	
}
LinkedList::~LinkedList()
{
	if(head_ != nullptr)
	{
		delete head_;
	}
	if(tail_ != nullptr)
	{
		delete tail_;
	}
}

LinkedNode * LinkedList::getHead()
{
	return head_;

}
LinkedNode * LinkedList::getTail() 
{
	return tail_;
}

void LinkedList::setHead(LinkedNode * head) 
{
	head_ = head;
}

void LinkedList::setTail(LinkedNode * tail)
{
	tail_ = tail;
}
	
bool LinkedList::isEmpty() 
{
	return (head_ == nullptr);
}

int LinkedList::getLength()
{
	int length = 0;
	LinkedNode * temp = head_;
	while(temp != nullptr)
	{
		length++;
		temp = temp->getNextLinkedNode();
	}
	delete temp;
	return length;
}

void LinkedList::insert(int element)
{
	std::cout << "Inserting " << element << "..." << std::endl;
	LinkedNode * temp = new LinkedNode(element);
	if(head_ == nullptr) {head_ = temp;}
	else if(tail_ == nullptr)
	{
		tail_ = temp;
		head_->setNextLinkedNode(tail_);
		tail_->setPrevLinkedNode(head_);
	}
	else
	{
		temp->setPrevLinkedNode(tail_);
		tail_->setNextLinkedNode(temp);
		tail_ = temp;
	}
}

void LinkedList::printList()
{
	LinkedNode * temp = head_; 
	std::cout<< temp->getData();
	while (temp->hasNextLinkedNode())
	{
		temp = temp->getNextLinkedNode();
		std::cout<< " --> " << temp->getData();
		
	}
	std::cout << std::endl;
	//temp->setPrevLinkedNode(nullptr);
	//delete temp;
}

void LinkedList::removeNode(int key)
{
	if(key == head_->getData()) // Case #1: Key is the Head.
	{
		if(getLength() > 1)
		{
			LinkedNode * currentHead = head_;
			LinkedNode * nextNode = head_->getNextLinkedNode();
			head_ = nextNode;
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
	else if(key == tail_->getData()) // Case #2: Key is the Tail.
	{
		LinkedNode * previousNode = nullptr;
		LinkedNode * currentNode = head_;
		while(currentNode->hasNextLinkedNode())
		{
			previousNode = currentNode;
			currentNode = currentNode->getNextLinkedNode();
			
			//if(currentNode->getNextLinkedNode() == tail_)
			//{
			//	break;
			//}
		}
		
		previousNode->setNextLinkedNode(nullptr);
		tail_ = previousNode;
		delete currentNode;
	}
	else // Case #3: Key is somewhere else.
	{
		//trash code
	}
}