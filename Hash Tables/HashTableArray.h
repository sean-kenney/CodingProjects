/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"
#include "HashEntry.h"

enum Method{LINEAR, QUADRATIC};

class HashTableArray : public HashTable
{
	public:
		HashTableArray(int size, Method method);
		HashTableArray(const HashTableArray & arr);
		~HashTableArray();
		int getSize();
		void setSize(int size);
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();

	private:
		HashEntry * entry_;
	int size_;
		Method method_;

};
#endif