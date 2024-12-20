/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashTable.h"
#include "HashEntry.h"
#include "DoublyLinkedList.h"


class HashTableChaining : public HashTable
{
    public: 
        HashTableChaining(int size);
        HashTableChaining(const HashTableChaining & arr);
        ~HashTableChaining();
        int getSize();
        void insert(int key, int value);
        int search(int key);
        void remove(int key);
        void print();
        
    private:
        int size_;
        DoublyLinkedList * entry_;
        

};

#endif