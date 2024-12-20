#include "TreeNode.h"

/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

TreeNode::TreeNode() : data_(0), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(0)
{ //default constructor
}

TreeNode::TreeNode(int data) : data_(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(0)
{ //overloaded constructor
}

TreeNode::TreeNode(TreeNode & node) //copy constructor
{
	data_ = node.data_;
	leftChild_ = node.getLeftChild();
	rightChild_ = node.getRightChild();
	parent_ = node.getParent();
	color_ = node.color_;
}

TreeNode::~TreeNode() //destructor
{
	if(leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if(rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

void TreeNode::setParent(TreeNode * parent) //sets parent
{
	parent_ = parent;
}

void TreeNode::setLeftChild(TreeNode * leftChild) //sets leftChild
{
	leftChild_ = leftChild;
}

void TreeNode::setRightChild(TreeNode * rightChild) //sets rightChild
{
	rightChild_ = rightChild;
}

void TreeNode::setData(int data) //sets the data
{
	data_ = data;
}

void TreeNode::setColor(bool color) //sets the color
{
	color_ = color;
}

TreeNode * TreeNode::getParent() //gets parent
{
	return parent_;
}

TreeNode * TreeNode::getLeftChild() //gets leftChild
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild() //gets rightChild
{
	return rightChild_;
}

int TreeNode::getData() //gets the data
{
	return data_;
}

bool TreeNode::getColor() //gets the color
{
	return color_;
}
