/* 
I pledge that I have never given nor
received any help on this assignment
smkenney
*/

#include <iostream>
#include <fstream>
#include "HashTableArray.h"
#include "HashTableCuckoo.h"
#include "HashTableChaining.h"
#include "HashTable.h"

//hash table functions 
void linearProbing();
void quadraticProbing();
void separateChaining();
void cuckooHashing();

int main()
{
    int hashChoice(0); //stores the desired hash function
    std::cout << "Welcome to Blue IV's can of Who Hash!" << std::endl;
    std::cout << std::endl;
    while(hashChoice != 5) //loop through until they quit the function
    {
        std::cout << "1) Linear Probing" << std::endl;
        std::cout << "2) Quadratic Probing" << std::endl;
        std::cout << "3) Separate Chaining" << std::endl;
        std::cout << "4) Cuckoo Hashing" << std::endl;
        std::cout << "5) Quit Program" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> hashChoice; //stores their selection
        if(hashChoice == 1) //if they choose linear probing call that
        {
            linearProbing();
        }
        else if(hashChoice == 2) //if they choose quad probing call that
        {
            quadraticProbing();
        }
        else if(hashChoice == 3) //if they choose separate chaining call that
        {
            separateChaining();
        }
        else if(hashChoice == 4) //if they choose cuckoo hashing call that
        {
            cuckooHashing();
        }
        else if(hashChoice == 5) //if they want to quit print goodbye message
        {
            std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
        }
        else //otherwise the selection is invalid and they need to try again
        {
            std::cout << "Invalid selection! Please try again!" << std::endl; 
        }
    }
    return 0;
}
void linearProbing() //function for linear probing
{
    int size(0); //stores the size of table
    int choice(0); 
    int count(0);
    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size; //takes the users input
    HashTableArray arr(size, LINEAR); //create hashtable array of entered size
    int key(0); //stores the key
    int value(0); //stores the value
    std::ifstream file;
    file.open("data.txt"); //opens file
    while(!file.eof()) //while not at the end of file
    {
        count++; //increase count
        if (count >= size) //if the count is too big for the table they need choose a new size
        {
            std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
            file.close();
            return;
        }
        file >> key;
        file >> value;
        arr.insert(key,value); //insert values in hashtable
    }
    file.close(); //closes file
    arr.print(); //prints table
    while(choice != 4) //loop until they want to go back
    {
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> choice; //stores their choice
        std::cout << std::endl;
        if(choice == 1) //if they choose to search
        {
            std::cout << "Search (Please enter a Key): ";
            std::cin >> key; //store their key
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0) //if key is in the table 
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
        
            }
            else //key is not in the table
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }
        }
        else if(choice == 2) //if they choose to remove 
        {
           std::cout << "Remove (Please enter a Key): ";
           std::cin >> key;
           std::cout << std::endl;
           arr.remove(key);
        }
        else if(choice == 3) //if they want to print
        {
            arr.print();
        }
        else if(choice == 4) //if they want to return to main menu you dont need to do anything
        {
        }
        else //otheriwse its invalid
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        }
    }

}
void quadraticProbing() //pretty much same thing but for quadratic probing
{
    int size(0);
    int choice(0);
    int count(0);
    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableArray arr(size, QUADRATIC);
    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt");
    while(!file.eof())
    {
        count++;
        if (count >= size)
        {
            std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
            file.close();
            return;
        }
        file >> key;
        file >> value;
        arr.insert(key,value);
    }
    file.close();
    arr.print();
    while(choice != 4)
    {    
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        if(choice == 1)
        {
            std::cout << "Search (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0)
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
            }
            else
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }
        }
        else if(choice == 2)
        {
            std::cout << "Remove (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            arr.remove(key);
        }
        else if(choice == 3)
        {
            arr.print();
        }
        else if(choice == 4)
        {
        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        }
    }
}
void separateChaining() //same process as the others but for seperate chaining
{
    int size(0);
    int choice(0);
    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableChaining arr(size);
    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt");
    while(!file.eof())
    {
        file >> key;
        file >> value;
        arr.insert(key,value);
    }
    file.close();
    arr.print();
    while(choice != 4)
    {
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        if(choice == 1)
        {
            std::cout << "Search (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0)
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
            }
            else
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }
        }
        else if(choice == 2)
        {
            std::cout << "Remove (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            arr.remove(key);
        }
        else if(choice == 3)
        {
            arr.print();
        }
        else if(choice == 4)
        {
        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        }
    }
}
void cuckooHashing() //same process but for cuckoo hashing
{
    int size(0);
    int choice(0);
    int count(0);
    std::cout << "Please enter the size of the Hash Table you wish to create: ";
    std::cin >> size;
    HashTableCuckoo arr(size);
    int key(0);
    int value(0);
    std::ifstream file;
    file.open("data.txt");
    while(!file.eof())
    {
        count++;
        if (count >= size)
        {
            std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
            file.close();
            return;
        }
        file >> key;
        file >> value;
        arr.insert(key,value);
        if(arr.getCycle() == true)
        {
            file.close();
            return;
        }
    }
    file.close();
    arr.print();
    while(choice != 4)
    {
        std::cout << std::endl;
        std::cout << "1) Search for Entry" << std::endl;
        std::cout << "2) Remove Entry" << std::endl;
        std::cout << "3) Print HashTable" << std::endl;
        std::cout << "4) Return to Main Menu" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        if(choice == 1)
        {
            std::cout << "Search (Please enter a Key): ";

            std::cin >> key;
            std::cout << std::endl;
            value = arr.search(key);
            if(value != 0)
            {
                std::cout << "Key: " << key << "  " << "Value: " << value << std::endl;
            }
            else
            {
                std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
            }
        }
        else if(choice == 2)
        {
            std::cout << "Remove (Please enter a Key): ";
            std::cin >> key;
            std::cout << std::endl;
            arr.remove(key);
        }
        else if(choice == 3)
        {
            arr.print();
        }
        else if(choice == 4)
        {
        }
        else
        {
            std::cout << "Invalid Selection! Please try again!" << std::endl;
        }
    }
}