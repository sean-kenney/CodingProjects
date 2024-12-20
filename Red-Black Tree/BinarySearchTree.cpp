#include "BinarySearchTree.h"

/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

BinarySearchTree::BinarySearchTree() : root_(nullptr) //default constructor sets the root to null
{
}

BinarySearchTree::~BinarySearchTree() //default destructor
{
	if(root_ != nullptr)
	{
		delete root_;
	}
}

TreeNode * BinarySearchTree::getRoot() //returns the root of the tree
{
	return root_;
}

void BinarySearchTree::setRoot(TreeNode * root) //sets the root of the tree
{
    root_ = root;
}

void BinarySearchTree::insert(int value) //inserts the value into the tree
{
	TreeNode * node = new TreeNode(value); //creates a new treeNode with the desired value
	root_ = insertNode(root_, node); //calls the helper function
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * newNode) //takes two nodes and returns the root
{
	if(root == nullptr) //if the node is at the end of the tree return the new node
	{
		return newNode;
	}
	else
	{
		if(newNode->getData() < root->getData()) //if the new node is smaller than the "root" it belongs in the left side
		{
			//Left Subtree
			root->setLeftChild(insertNode(root->getLeftChild(),newNode)); //uses recursion by calling the helper function on the leftChild 
			root->getLeftChild()->setParent(root); //sets the leftChild's parent to be the "root"
		}
		else
		{
			//Right Subtree
			root->setRightChild(insertNode(root->getRightChild(), newNode)); //uses recursion by calling the helper function on the rightChild
			root->getRightChild()->setParent(root); //sets the rightChild's parent to be the "root"
		}
		return root; //returns the "root"
	}
}
void BinarySearchTree::inorder(TreeNode * root) //loops through the tree in inorder (prints from bottom left up)
{
	if(root == nullptr) //if the root is null there is nothing to go through
	{
		return;
	}
	inorder(root->getLeftChild()); //uses recursion to get all of the left children it can without having to go right
	std::cout << root->getData() << " "; //prints the root
	inorder(root->getRightChild()); //once all of the left children of that right child are found it goes to the next lowest right child and repeats
}
void BinarySearchTree::preorder(TreeNode * root) //loops through the tree in preorder 
{

	if(root == nullptr) //if the root is null there is nothing to go through (prints from top down, left to right)
	{
		return;
	}
	std::cout << root->getData() << " "; //prints the root
	preorder(root->getLeftChild()); //uses recursion to go to the left child
	preorder(root->getRightChild()); //after the left children are found it starts on the right
	
}
void BinarySearchTree::postorder(TreeNode * root) //loops through the tree in postorder (goes from left to right, bottom to top)
{
	
	if(root == nullptr) //if the root is null there is nothing to go through
	{
		return;
	}
	postorder(root->getLeftChild()); //uses recursion to get all the left children
	postorder(root->getRightChild()); //then gets the right children
	std::cout << root->getData() << " "; //and prints the root last
}

