/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#include "HashEntry.h"
HashEntry::HashEntry(int key, int value) //constructor
{
   key_= key;
   value_ = value; 
   status_ = EMPTY;
}
HashEntry::HashEntry() //default constructor
{
    key_ = 0;
    value_ =  0;
    status_ = EMPTY;
}
HashEntry::~HashEntry() //destructor
{
    
}
int HashEntry::getKey()
{
    return key_;
}
void HashEntry::setKey(int key) 
{
    key_ = key;
}
int HashEntry::getValue()
{
    return value_;
}
void HashEntry::setValue(int value) 
{
    value_ = value;
}
Status HashEntry::getStatus() 
{
    return status_;
}
void HashEntry::setStatus(Status status) 
{
    status_ = status;
}