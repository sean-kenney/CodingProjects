//#include "LinkedNode.h"
#include "LinkedList.h"
int main()
{
	LinkedNode * node1 = new LinkedNode(15);
	LinkedNode * node2 = new LinkedNode(10);
	LinkedNode * node3 = new LinkedNode(7);
	
	node1->setNextLinkedNode(node2);
	node2->setNextLinkedNode(node3);
	
	std::cout << "Next Node: " << node1->getNextLinkedNode()->getData() << std::endl;
	std::cout << "Has a previous node ? " << node1->hasPrevLinkedNode() << std::endl;
	node1->setPrevLinkedNode(node3);
	std::cout << "Prev Node: " << node1->getPrevLinkedNode()->getData() << std::endl;
	std::cout << "Has a previous node ? " << node1->hasPrevLinkedNode() << std::endl;
	
	LinkedList * list1 = new LinkedList();
	std::cout << list1->isEmpty() << std::endl;
	
	list1->insert(10);
	list1->insert(3);
	list1->insert(4);
	
	std::cout << "Printing list" << std::endl;
	
	list1->printList();
	
	return 0;
}