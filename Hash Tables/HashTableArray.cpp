/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#include "HashTableArray.h"
#include <iostream>
HashTableArray::HashTableArray(int size, Method method) //normal constructor
{
    entry_ = new HashEntry[size];
    size_ = size;
    method_ = method;
}
HashTableArray::HashTableArray(const HashTableArray & arr) //copy constructor
{
    
    entry_ = arr.entry_;

}
HashTableArray::~HashTableArray() //destructor
{
   if(entry_ != nullptr)
    {
        delete [] entry_;
    }
}
void HashTableArray::insert(int key, int value) 
{
    HashEntry temp(key, value); //create a temporary hash entry
    int hashIndex(0);

    if(method_ == LINEAR) //if linear probing
    {
       hashIndex = key % size_; //stores the hash index
       if(entry_[hashIndex].getStatus() == EMPTY || entry_[hashIndex].getStatus() == REMOVED) //if the slot is open
       {
            entry_[hashIndex] = temp; //add the entry 
            entry_[hashIndex].setStatus(OCCUPIED); //change the status 

       }
       else
       {
            for(int i = hashIndex; i < size_; i++) //loop through the array
            {
                if(entry_[i].getStatus() == EMPTY || entry_[i].getStatus() == REMOVED) //if a slot is open
                {
                    entry_[i] = temp; //insert 
                    entry_[i].setStatus(OCCUPIED); //change status
                    break;

                }
                
                if(i + 1 == size_) //if one away from max size
                {
                    i = 0; //start the loop over
                }
                
            }
       }
    }
    else if(method_ == QUADRATIC) //if quadratic probing
    {
       hashIndex = key % size_;
       if(entry_[hashIndex].getStatus() == EMPTY || entry_[hashIndex].getStatus() == REMOVED) //if a slot is open
       {
            entry_[hashIndex] = temp; //insert
            entry_[hashIndex].setStatus(OCCUPIED); //change status
       }
       else
       {
        for(int i = 1; i < size_; i++) //loop through starting at 1
        {
            int newHashIndex = (hashIndex + i * i) % size_; //stores the hash index
            if(entry_[newHashIndex].getStatus() == EMPTY || entry_[newHashIndex].getStatus() == REMOVED) //if slot is open
            {
                entry_[newHashIndex] = temp; //insert
                entry_[newHashIndex].setStatus(OCCUPIED); //change status
                break;
            }
            
        }
       }
    }
}
int HashTableArray::search(int key) //search for desired entry
{
   for(int i = 0; i < size_; i++) //loop through
   {
    if(entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED) //if its the right key and full 
    {
        return entry_[i].getValue(); //return

    }
   }
   return 0; //otherwise return zero to show not found
   
}
void HashTableArray::remove(int key) //remove an entry
{
    
    for(int i = 0; i < size_; i++) //loop through
    {
        if(entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED) //if its the right key and full 
        {
            entry_[i].setStatus(REMOVED); //change status
            std::cout << "Key " << key << " removed." << std::endl; //print the removed key
			return;
        }
    }
    std::cout << "Key " << key << " not found! " << std::endl; //otherwise print that the key is not found 
}
void HashTableArray::print()
{
    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++) //loops through
    {
        if(entry_[i].getStatus() == OCCUPIED) //if the slot is filled
        {
            std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl; //print it
        }
        else
        {
            std::cout << "[" << i << "]: " << std::endl; //otherwise print just the position 
        }
    }
    std::cout << "***********************************" << std::endl; //for formatting



}
int HashTableArray::getSize() 
{
    return size_;
}