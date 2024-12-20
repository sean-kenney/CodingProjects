/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : LinkedList() //constructs a linkedList
{

}

DoublyLinkedList::~DoublyLinkedList() //never used
{

}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry data) 
{
   node = new LinkedNode(data,nullptr,nullptr); //creates new node, head and tail object
   LinkedNode * head = getHead();
   LinkedNode * tail = getTail();

   if(head == nullptr)  //if null set the node to be the head and tail
   {
        head = node;
        tail = node;
        setHead(head);
        setTail(tail);
   }
   else if(getLength() == 1) //if its one long set the tail to be the node
   {
        tail = node;
        setTail(tail);
        head->setNextLinkedNode(tail);
        tail->setPrevLinkedNode(head);
   }
   else if(getLength() > 1) //otherwise set the node to be after the current tail, then adjust the node to be the tail
   {
        tail->setNextLinkedNode(node);
        node->setPrevLinkedNode(tail);
        tail = node;
        setTail(tail);
   }
   
    
   
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data) //same thing but it adds the node before the designated node
{
    LinkedNode * newNode = new LinkedNode(data,nullptr,nullptr);
    if (getHead() == nullptr)
    {
        if (getHead() == nullptr && getTail() == nullptr)
        {
            setHead(newNode);
        }
        else if (getHead() != nullptr && getTail()== nullptr)
        {
            setTail(newNode);
            getHead()->setNextLinkedNode(getTail());
            getTail()->setPrevLinkedNode(getHead());
        }
    }
    else
    {
        newNode -> setPrevLinkedNode(node -> getPrevLinkedNode()); 
        if (node->getPrevLinkedNode() == nullptr)
        {
            node->setPrevLinkedNode(newNode);
            newNode -> setNextLinkedNode(node);
            setHead(newNode);
        }
        else
        {
            node->getPrevLinkedNode()->setNextLinkedNode(newNode);
            node->setPrevLinkedNode(newNode); 
            newNode ->setNextLinkedNode(node);
        }
    }
    
}

void DoublyLinkedList::printList()
{
    LinkedNode * temp = getHead(); //creates a temp object startin at first node
	std::cout<< temp->getValue().getKey(); //prints the first node
	while (temp->hasNextLinkedNode()) //loops through until no more nodes
	{
		temp = temp->getNextLinkedNode(); //goes to next node
		std::cout<< " <--> " << temp->getValue().getKey(); //prints
	}
	std::cout << std::endl; //for formatting
}



int DoublyLinkedList::find(int key)
{
    LinkedNode * temp = getHead();
    while (temp != nullptr) //loops until it gets to a null pointer 
    {
        if (temp->getValue().getKey() == key) //if the keys match
        {
            return temp->getValue().getKey(); //returms the key and ends the loop
        }
        temp = temp->getNextLinkedNode(); //move to next loop
    }
    return 0;
}

void DoublyLinkedList::removeNode(int key)
{
	if(key == getHead()->getValue().getKey())
	{
		if(getHead()->hasNextLinkedNode())
		{
			LinkedNode * currentHead = getHead();
			LinkedNode * nextNode = getHead()->getNextLinkedNode();
			setHead(nextNode);
			nextNode->setPrevLinkedNode(nullptr);
			currentHead->setNextLinkedNode(nullptr);
			delete currentHead;
		}
		else
		{
			LinkedNode * currentHead = getHead();
			setHead(nullptr);
			setTail(nullptr);
			delete currentHead;
		}
	}
	else if(key == getTail()->getValue().getKey())
	{
		if(LinkedList::getTail()->hasPrevLinkedNode())
		{
			LinkedNode * currentTail = getTail();
			LinkedNode * previousNode = getTail()->getPrevLinkedNode();
			setTail(previousNode);
			previousNode->setNextLinkedNode(nullptr);
			currentTail->setPrevLinkedNode(nullptr);
			delete currentTail;
		}
	}
	else
	{
		LinkedNode * currentNode = getHead();
		
		bool isFound = false;
		
		while(currentNode->hasNextLinkedNode() && !isFound)
		{
			currentNode = currentNode->getNextLinkedNode();
			if(currentNode->getValue().getKey() == key)
			{
				isFound = true;
			}
		}
		if(isFound)
		{
			currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
			currentNode->getNextLinkedNode()->setNextLinkedNode(currentNode->getPrevLinkedNode());
			currentNode->setNextLinkedNode(nullptr);
			currentNode->setPrevLinkedNode(nullptr);
			delete currentNode;
		}
		else
		{
			std::cout << "Key not found!" << std::endl;
		}
	}
}
int DoublyLinkedList::searchKey(int key)
{
    LinkedNode * head = getHead();
    if(head == nullptr)
    {
    
        return 0;
    }
    LinkedNode * current = head;
    while (current != nullptr)
    {
        if (current->getValue().getKey() == key)
        {
            return key;
        }
        current = current->getNextLinkedNode();
    }
    return 0;
}