#ifndef REDBLACKTREENODE_H
#define REDBLACKTREENODE_H

#include "BinarySearchTree.h"

/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

class RedBlackTree : public BinarySearchTree //
{
    public:
        RedBlackTree(); //default constructor
        virtual ~RedBlackTree(); //destructor
        virtual void insert(int data); //inserts into red black tree
        void printBlackNodes(TreeNode * root); //prints black nodes using preorder traversal
        void printRedNodes(TreeNode * root); //prints red nodes using postorder traversal
        int getHeight(TreeNode * root); //gets the height of the red black tree
	protected:
        void balanceColor(TreeNode *& root, TreeNode *& newNode); //maintains correct colors
    private:
        void rotateLeft(TreeNode *& root, TreeNode *& newNode); //rotates left on the newNode
        void rotateRight(TreeNode *& root, TreeNode *& newNode); //rotates right on the newNode
};
#endif