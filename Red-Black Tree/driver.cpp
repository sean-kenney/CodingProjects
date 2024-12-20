#include "RedBlackTree.h"

/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

int main()
{
	int temp = 0;
    std::ifstream file; //file i/o from phase 1
    file.open("data-2.txt");
	BinarySearchTree searchTree;
    RedBlackTree rBTree;
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> temp;
            rBTree.insert(temp);
			searchTree.insert(temp);
        }
    }
    file.close();
	std::cout << "Root of the Binary Search Tree: " << searchTree.getRoot()->getData() << std::endl; //checking the root from phase 2
    std::cout << "Black Nodes: "; 
    rBTree.printBlackNodes(rBTree.getRoot()); //prints the black nodes 
	std::cout << std::endl;
    std::cout << "Red Nodes: ";
    rBTree.printRedNodes(rBTree.getRoot()); //prints the red nodes
	std::cout << std::endl;
    std::cout << "Root: " << rBTree.getRoot() -> getData() << std::endl; //gets the redBlackTree root
    if(rBTree.getRoot()->getColor() == 1) //if the root is 1(black) print that it is black
    {
        std::cout << "Root Color: BLACK" << std::endl;
    }
    else if(rBTree.getRoot()->getColor() == 0) //if the root is 0(red) print that it is red
    {
        std::cout << "Root Color: RED" << std::endl;
    }
    std::cout << "Height: " << rBTree.getHeight(rBTree.getRoot()) << std::endl; //print the height
    return 0;
}