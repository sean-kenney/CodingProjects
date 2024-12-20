#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

class BinarySearchTree
{
	public:
		BinarySearchTree();
		~BinarySearchTree();
		TreeNode * getRoot();
		void setRoot(TreeNode * root);
		void insert(int value);
		void inorder(TreeNode * root);
		void preorder(TreeNode * root);
		void postorder(TreeNode * root);
	protected:
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
	private:
		TreeNode * root_;
};
#endif