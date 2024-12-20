/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#include "HashTableChaining.h"
#include <iostream>

HashTableChaining::HashTableChaining(int size) //constructor
{
    entry_ = new DoublyLinkedList[size];
    size_ = size;
}

HashTableChaining::HashTableChaining(const HashTableChaining & arr) //copy constructor
{
    entry_ = arr.entry_;
}

HashTableChaining::~HashTableChaining() //destructor
{
    if(entry_ != nullptr)
    {
        delete [] entry_;
    }
    
    
}

int HashTableChaining::getSize() //returns size
{
    return size_;
}

void HashTableChaining::insert(int key, int value) //inserts the desired key and value
{
  HashEntry entry(key,value);
  int index = key % size_;
  LinkedNode * node = new LinkedNode(entry,nullptr, nullptr);
  if(entry_[index].getHead() == nullptr)
  {
    DoublyLinkedList list;
    entry_[index] = list;
    entry_[index] = list;
    entry_[index].insertLinkedNode(node,entry);
    return;
  }
  else
  {
    entry_[index].insertLinkedNode(node,entry);
  }
  delete node;
}

int HashTableChaining::search(int key) //searches for the key
{
    for (int i = 0; i < size_; i++) //loop through
    {
       if(entry_[i].find(key) != 0) //if find returns not 0 
       {
            return entry_[i].find(key); //return value
       }
    }
    return 0; //otherwise return 0
}
void HashTableChaining::remove(int key)
{
   
    for (int i = 0; i < size_; i++) //loop through
    {
        if (entry_[i].searchKey(key) == key) //search to see if the key is there
        {
            entry_[i].removeNode(key); //remove the key
            std::cout << "Key " << key << " removed." << std::endl;
			return;
        }
    }
    std::cout << "Key " << key << " is not present in the table!" << std::endl; //otherwise says its not there
    

   
}
void HashTableChaining::print() //prints the table
{
   
    int count(0);
    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++)
    {
       std::cout << "[" << i << "]: ";
       if(entry_[i].getHead() != nullptr) //if there is a head
       {
            entry_[i].printList(); //print the list
       }
       std::cout << std::endl;
    }
    std::cout << "***********************************" << std::endl;
    
}