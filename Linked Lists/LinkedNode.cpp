#include "LinkedNode.h"

LinkedNode::LinkedNode(int data) : Node(data), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
	
}

LinkedNode::LinkedNode(int data, LinkedNode * nextNode) : Node(data), nextLinkedNode_(nextNode)
{
}

LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode)
{
	
}

LinkedNode::~LinkedNode()
{
	if(nextLinkedNode_ != nullptr)
	{
		delete nextLinkedNode_;
	}
	if(prevLinkedNode_ != nullptr)
	{
		delete prevLinkedNode_;
	}
	
}

LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * next)
{
	nextLinkedNode_ = next;
}

bool LinkedNode::hasNextLinkedNode()
{
	return nextLinkedNode_ != nullptr;
}
LinkedNode * LinkedNode::getPrevLinkedNode()
{
	return prevLinkedNode_;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasPrevLinkedNode()
{
	return prevLinkedNode_ != nullptr;
}
