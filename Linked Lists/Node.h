#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <string>
class Node
{
	public:
		Node() {}
		Node(int data);
		~Node() {};
		void setData(int data);
		int getData();
		
	private:
		int data_;
};
#endif