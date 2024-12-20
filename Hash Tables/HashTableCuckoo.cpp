/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#include "HashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo(int size) //constructor
{
    size_ = size;
    entry_ = new HashEntry[size_];
    entry_2 = new HashEntry[size_];
    cycle_ = false;
}

HashTableCuckoo::HashTableCuckoo(const HashTableCuckoo & arr) //constructor
{
    entry_ = arr.entry_;
    entry_2 = arr.entry_;
}

HashTableCuckoo::~HashTableCuckoo() //destructor
{
    if(entry_ != nullptr)
    {
        delete [] entry_;
    }
    if(entry_2 != nullptr)
    {
        delete [] entry_2;
    }
}
int HashTableCuckoo::getSize() //returns size
{
    return size_;
}
void HashTableCuckoo::insert(int key, int value) //inserts the desired key and value
{
   HashEntry temp(key,value); //creates a temporary entry
   int importKey = key;
   int hashIndex = key % size_;
   int tempHashIndex = hashIndex;
   int tempKey(0);
   int tempValue(0);
   int temp2key(0);
   int count(0);

    while(count <= size_) //loops until the count is greater than size
    {
        if(entry_[tempHashIndex].getStatus() == OCCUPIED) //if the slot is full add it and kick out current one
        {
            tempKey = entry_[tempHashIndex].getKey();
            tempValue = entry_[tempHashIndex].getValue();
            HashEntry temp2(tempKey,tempValue);
            entry_[tempHashIndex] = temp;
            entry_[tempHashIndex].setStatus(OCCUPIED);
            tempHashIndex = (tempKey/size_) % size_;
        
            if(entry_2[tempHashIndex].getStatus() == OCCUPIED) //if the next slot is full kick it out and add temp2
            {
                tempKey = entry_2[tempHashIndex].getKey();
                tempValue = entry_2[tempHashIndex].getValue();
                HashEntry temp3(tempKey,tempValue);
                temp = temp3;
                entry_2[tempHashIndex] = temp2;
                entry_2[tempHashIndex].setStatus(OCCUPIED);
                tempHashIndex = tempKey % size_;
                temp2key = entry_[tempHashIndex].getKey();
            }
            else
            {
                entry_2[tempHashIndex] = temp2;
                entry_2[tempHashIndex].setStatus(OCCUPIED);
                return;
        }
        }
        else
        {
            entry_[tempHashIndex] = temp;
            entry_[tempHashIndex].setStatus(OCCUPIED);
            return;
        }
        count++;
    }
    if(count > size_) //if the count starts bigger than size
    {
        std::cout << "Cycle Present - Rehash!" << std::endl;
        std::cout << "Key Unpositioned: " << key << std::endl;
        cycle_ = true;
    }

}
int HashTableCuckoo::search(int key)
{
    for (int i = 0; i < size_; i++) //loop through both tables 
    {
        if (entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED) //if the table has it return
        {
            return entry_[i].getValue();
        }
        if (entry_2[i].getKey() == key && entry_2[i].getStatus() == OCCUPIED) //if the second table has it return
        {
            return entry_2[i].getValue();
        }
    }
    return 0;
}
void HashTableCuckoo::remove(int key) 
{
    for (int i = 0; i < size_; i++) //search through both tables, if you find the key and its occupied, return value
    {
        if (entry_[i].getKey() == key && entry_[i].getStatus() == OCCUPIED)
        {
            entry_[i].setStatus(REMOVED);
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
        else if (entry_2[i].getKey() == key && entry_2[i].getStatus() == OCCUPIED)
        {
            entry_2[i].setStatus(REMOVED);
            std::cout << "Key " << key << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Key " << key << " is not present in the tables!" << std::endl;

}
void HashTableCuckoo::print()
{
    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++) //loop through the first table and print everything
    {
        if(entry_[i].getStatus() == OCCUPIED)
        {
            std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
        }
        else
        {
            std::cout << "[" << i << "]: " << std::endl;
        }
    }
    std::cout << "***********************************" << std::endl;

    std::cout << "***********************************" << std::endl;
    for(int i = 0; i < size_; i++) //loop through the second table and print everything
    {
        if(entry_2[i].getStatus() == OCCUPIED)
        {
            std::cout << "[" << i << "]: " << entry_2[i].getKey() << std::endl;
        }
        else
        {
            std::cout << "[" << i << "]: " << std::endl;
        }
    }
    std::cout << "***********************************" << std::endl;
}
int HashTableCuckoo::hash(int option, int key) //helper function 
{
    switch (option)
    {
        case 1: return key % size_; 
        case 2: return (key/size_) % size_; 
    }
    return key % size_;
}
bool HashTableCuckoo::getCycle()
{
    return cycle_;
}