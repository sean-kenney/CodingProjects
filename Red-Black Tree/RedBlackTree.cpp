#include "RedBlackTree.h"

/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

RedBlackTree::RedBlackTree() : BinarySearchTree()
{//default constructor
}

RedBlackTree::~RedBlackTree()
{//destructor
}

void RedBlackTree::insert(int data)
{
    TreeNode * newNode = new TreeNode(data); //stores the data in a newNode
    if (newNode -> getColor() == 0) //if the node is red 
    {
        setRoot(BinarySearchTree::insertNode(getRoot(), newNode)); //uses the BST insert node to set the root 
        TreeNode * root = getRoot(); //creates a treeNode pointer for the root
        balanceColor(root,newNode); //balances the color
    }
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode * newRightChild = newNode->getRightChild();
    TreeNode * temp;
    newNode->setRightChild(newRightChild->getLeftChild()); //sets newRightChild's left child as newNode's right child
    if(newNode->getRightChild() != nullptr) //if right child isn't null
    {
        newNode->getRightChild()->setParent(newNode); //sets the right child's parent to the newNode
    }
    newRightChild->setParent(newNode->getParent()); //sets newRightChild's parent to newNodes' parent
    temp = newNode->getParent();
    if(newNode->getParent() == nullptr) //if newNode doesn't have a parent it must be the root
    {
        root = newRightChild; //sets newRightChild as the root
        setRoot(root);
    }
    else if (newNode == temp->getLeftChild()) //if newNode is the left child
    {
        temp->setLeftChild(newRightChild);  //switches the left child to be the right child
    }
    else
    {
        temp->setRightChild(newRightChild); //if it is right child, gives the right child the original left child
    }
    newRightChild->setLeftChild(newNode); //set newNode as the left child
    newNode->setParent(newRightChild); //the original right child becomes the parent of newNode
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode) //same as rotateLeft but switch rights and lefts
{
    TreeNode * newLeftChild = newNode->getLeftChild();
    TreeNode * temp;
    newNode->setLeftChild(newLeftChild->getRightChild());

    if(newNode->getLeftChild() != nullptr)
    {
        newNode->getLeftChild()->setParent(newNode);
    }
    newLeftChild->setParent(newNode->getParent());
    temp = newNode -> getParent();
    if(newNode->getParent() == nullptr)
    {
        root = newLeftChild;
        setRoot(root);
    }
    else if (newNode == temp->getLeftChild())
    {
        temp->setLeftChild(newLeftChild);
    }
    else
    {
        temp->setRightChild(newLeftChild);
    } 
   newLeftChild->setRightChild(newNode);
   newNode->setParent(newLeftChild); 
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{   
   
    TreeNode * newParent = nullptr;
    TreeNode * newDoubleParent = nullptr;
    TreeNode * newAdjParent = nullptr;
    bool tempColor(0);
    

    if (newNode -> getParent() != nullptr) //if newNode has a parent
    {

        while ((newNode != root) && (newNode -> getColor() == 0) && (newNode -> getParent() -> getColor() == 0)) //while newNode is not thr root, its color is red, and its parent is red
        {
            newParent = newNode -> getParent();
            newDoubleParent = newParent -> getParent();

            if (newDoubleParent -> getLeftChild() == newParent) //if newParent is a left child
            { 
                newAdjParent = newDoubleParent -> getRightChild(); //sets the adjacent parent to be the right child

        
                if (newAdjParent != nullptr && newAdjParent -> getColor() == 0) //if the adjacent parent is red  
                {
                    newDoubleParent -> setColor(0); //sets the parents parent to red
                    newParent -> setColor(1); //sets parent to black
                    newAdjParent -> setColor(1); //sets adjacent parent to black
                    newNode = newDoubleParent;
                }
                else //if the adjacent parent is black or null
                {
                    
                    if (newNode == newParent->getRightChild()) //if newNode is the right child
                    {
                        rotateLeft(root, newParent); //rotates newParent left
                        newNode = newParent;
                        newParent = newNode -> getParent();
                    }

                    else //if newNode is the left child
                    {
                        rotateRight(root,newDoubleParent); //rotates doubleParent to the right
                        tempColor = newParent -> getColor(); //stores newParents color
                        newParent -> setColor(newDoubleParent -> getColor()); //gives newParent doubleParents color
                        newDoubleParent->setColor(tempColor); //gives doubleParent newParents color
                        newNode = newParent;
                    }
                    
                }
            }
            else //if newParent is right child of its parent
            {
                newAdjParent = newDoubleParent -> getLeftChild(); //set the adjacent parent to be the leftChild

                if ((newAdjParent != nullptr) && (newAdjParent -> getColor() == 0)) //if the adjacent parent isnt black or null
                {
                    newDoubleParent -> setColor(0); //sets double parent to red
                    newParent -> setColor(1); //set parent to black
                    newAdjParent -> setColor(1); //set adjacent parent to black
                    newNode = newDoubleParent;
                }

                else //otherwise
                {
                    if (newParent -> getLeftChild() == newNode) //if newNode is the left child
                    {
                        rotateRight(root, newParent);  //rotate the parent right 
                        newNode = newParent;
                        newParent = newNode -> getParent();
                    }
                    else //if newNode is the right child
                    { 
                        rotateLeft(root, newDoubleParent); //rotate the doubleParent to the left
                        tempColor = newParent -> getColor(); //temporarily store the parents color
                        newParent -> setColor(newDoubleParent -> getColor()); //give the doubleParent color to the parent
                        newDoubleParent -> setColor(tempColor); //give the parents color to the doubleParent
                        newNode = newParent;
                    }
                    
                }
            }
        }
    }
    root -> setColor(1);  //set the root to black
}

void RedBlackTree::printRedNodes(TreeNode * root)
{
    if (root == nullptr) //if the root is null return 
    {
        return;
    }
    else
    {
        printRedNodes(root->getLeftChild()); //uses recursion to go through the left side until you reach the bottom
        if (root-> getColor() == 0) //if its red print it
        {
            std::cout << root -> getData() << " ";
        }
        printRedNodes(root -> getRightChild()); //uses recursion to print the right children 
    }
}

void RedBlackTree::printBlackNodes(TreeNode * root)
{
    if (root == nullptr) //if the root is null return 
    {
        return;
    }
    else
    {
        if (root->getColor() == 1) //if its black print it
        {
            std::cout << root->getData() << " ";
        }
        printBlackNodes(root->getLeftChild()); //uses recursion to go through the left side until you reach the bottom
        printBlackNodes(root->getRightChild()); //uses recursion to print the right children
    }
}
int RedBlackTree::getHeight(TreeNode * root)
{
    if(root == nullptr) //if the root has no children the height is zero
    {
        return 0;

    }
    else
    {
        int leftHeight = getHeight(root->getLeftChild()); //uses recursion to go through the left side and add each row
        int rightHeight = getHeight(root->getRightChild());//uses recursion to go through the right side and add each row
        if(leftHeight >= rightHeight) //returns whichever height is greater +1
        {
            return leftHeight + 1; 
        }
        else
        {
            return rightHeight + 1; 
        }
    }
}