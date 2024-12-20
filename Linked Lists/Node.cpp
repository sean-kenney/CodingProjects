#include "Node.h"

Node::Node(int data)
{
	data_ = data;
}

void Node::setData(int data)
{
	data_ = data;
}

int Node::getData()
{
	return data_;
}