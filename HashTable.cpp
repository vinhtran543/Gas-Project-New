/**
Gaseek
* Team 7
Vinh Tran

* CIS 22C

* HashTable.cpp

*/
#include "HashTable.h";
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

HashTable::HashTable()                      //default constructor
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		Table[i] = new Node;
	}
}

HashTable::~HashTable()
{
	Nodeptr cursor;
	Nodeptr temp;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (Table[i] != NULL)
		{
			cursor = Table[i];
			while (cursor != NULL)
			{
				temp = cursor;
				cursor = cursor->next;
				delete temp;
			}
		}
	}
}

int HashTable::hash(string key)
{
	int index;
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];             //sum the ASCII values for each character in the string
	}
	index = sum % TABLE_SIZE;		  //dividing the summed ASCII values by 35 && storing remainder as my index
	return index;
}

void HashTable::addItem(string stationName, string address, double gasPriceRegular, double gasPricePremium, double gasPriceMidGrade)
{
	Nodeptr newNode = new Node(stationName, address, gasPriceRegular, gasPricePremium, gasPriceMidGrade);

	int index = hash(address);

	if (Table[index]->address == "")
	{
		Table[index] = newNode;
	}
	else
	{
		Nodeptr temp = Table[index];   //create temp Node to point to first node at indexB

		while (temp->next != NULL)   //scroll through Nodes at index until one's next points to NULL
		{
			temp = temp->next;
		}
		temp->next = newNode;      //insert new Node at the back of the list at the index
	}
}

int HashTable::numItemsAtIndex(int index)   //helper function for printTable()
{
	Nodeptr temp = Table[index];      //temp Node to point to first Node at the index

	int counter = 0;

	if (temp->address == "")          //if empty title, return 0 as counter
		return counter;
	else
	{
		while (temp != NULL)      //else while temp not NULL, increment counter
		{
			counter++;
			temp = temp->next;    //traverse through the list
		}
	}
	return counter;            //returns number of Nodes in bucket
}

void HashTable::printTable()
{
	Nodeptr p;
	cout << "Gas Station Hash Table:\n\n";

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		p = Table[i];
		cout << "-------------------------------------------\n";
		cout << "Index " << i << ":\n";
		cout << "Gas Station Name: " << p->stationName << endl;
		cout << "Gas Station Address: " << p->address << endl;
		cout << "Regular Gas Price: " << p->gasPriceRegular << endl;
		cout << "Premium Gas Price: " << p->gasPricePremium << endl;
		cout << "MidGrade Gas Price: " << p->gasPriceMidGrade << endl;
		cout << "Number values at this Index: " << numItemsAtIndex(i);
		cout << endl << endl << endl;
	}
}

void HashTable::saveHashTable(ofstream &fout)
{
    ifstream fin;
	fin.open("input.txt", ios_base::app);       //opens file and does not overwrite it
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(-1);
	}

	//ofstream fout;
	fout.open("outputHashTable.txt");
	if (fout.fail()) {
		cout << "saveHashTable(): Output file opening failed.\n";
		exit(-1);
	}

	Nodeptr p;
	fout << "Book Hash Table:\n\n";

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		p = Table[i];
		fout << "-------------------------------------------\n";
		fout << "Index " << i << ":\n";
		fout << "Gas Station Name: " << p->stationName << endl;
		fout << "Gas Station Address: " << p->address << endl;
		fout << "Regular Gas Price: " << p->gasPriceRegular << endl;
		fout << "Premium Gas Price: " << p->gasPricePremium << endl;
		fout << "MidGrade Gas Price: " << p->gasPriceMidGrade << endl;
		fout << "Number values at this Index: " << numItemsAtIndex(i);
		fout << endl << endl << endl;
	}
	fin.close();    //close read file
	fout.close();   //close write file
}

void HashTable::removeItem(string key)
{
	int index = hash(key);               //gets the index of the key that you want to remove

	if (Table[index]->address == "")  //case 1 if bucket is empty
	{
		cout << "removeItem(): Sorry, but " << key << " was not found in the Hash Table\n";   //error message if key not found in Hash Table
	}
	else if (Table[index]->address == key && Table[index]->next == NULL)   //case 2 if bucket has one elment in it and has matching key
	{
		Table[index] = new Node;

		cout << endl << key << " was removed from the Hash Table\n";
		cout << "\n\nSuccessfully removed data!!!\n";
	}
	else if (Table[index]->address == key)    //case 3 key is in the first itme in the bucket, multiple items in bucket
	{
		Nodeptr temp = Table[index];
		Table[index] = Table[index]->next;
		delete temp;

		cout << endl << key << " was removed from the Hash Table\n\n";
		cout << "\n\nSuccessfully removed data!!!\n";

	}
	else        //not the first one at index, but is located in the bucket
	{
		Nodeptr currentNode = Table[index]->next;
		Nodeptr previousNode = Table[index];

		while (currentNode != NULL && currentNode->address != key)  //traverse through list until NULL or until key matches
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		if (currentNode->address == key)
		{
			Nodeptr temp = currentNode;
			currentNode = currentNode->next;
			previousNode->next = currentNode;
			delete temp;

			cout << key << " was removed from the Hash Table\n";
		}
		else
			cout << "removeItem(): Sorry, but " << key << " was not found in the Hash Table\n";
	}
}

void HashTable::printBucket(int index)
{
	Nodeptr p = Table[index];

	if (p->address == "empty")
	{
		cout << "Index = " << index << " is empty\n";
	}
	else
	{
		cout << "Index <#>:" << index << endl << endl;

		while (p != NULL)
		{
			cout << "Index " << index << ":\n";
			cout << "Gas Station: " << p->stationName << endl;
			cout << "Gas Station Address: " << p->address << endl;
			cout << "Regular Gas Price: " << p->gasPriceRegular << endl;
			cout << "Premium Gas Price: " << p->gasPricePremium << endl;
			cout << "MidGrade Gas Price: " << p->gasPriceMidGrade << endl;
			cout << "Number values at this Index: " << numItemsAtIndex(index);
			cout << endl << endl;
            p = p->next;
		}
	}
}

void HashTable::saveHashBucket(ofstream &fout)
{
    ifstream fin;
	fin.open("input.txt", ios_base::app);       //opens file and does not overwrite it
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(-1);
	}

	//ofstream fout;
	fout.open("outputHashTableBucket.txt");
	if (fout.fail()) {
		cout << "saveHashBucket(): Output file opening failed.\n";
		exit(-1);
	}
    for(int i = 0; i < TABLE_SIZE; i++)
    {
             Nodeptr p = Table[i];

        if (p->address == "empty")
        {
            fout << "Index = " << i << " is empty\n";
        }
        else
        {
            fout << "Index <#>:" << i << endl << endl;

            while (p != NULL)
            {
                fout << "Index " << i << ":\n";
                fout << "Gas Station: " << p->stationName << endl;
                fout << "Gas Station Address: " << p->address << endl;
                fout << "Regular Gas Price: " << p->gasPriceRegular << endl;
                fout << "Premium Gas Price: " << p->gasPricePremium << endl;
                fout << "MidGrade Gas Price: " << p->gasPriceMidGrade << endl;
                fout << "Number values at this Index: " << numItemsAtIndex(i);
                fout << endl << endl;
                p = p->next;
            }
        }
    }
    fin.close();    //close read file
	fout.close();   //close write file
}

int HashTable::listGas(string key)
{
	int index = hash(key);
    bool found = false;
    cout << "\n\n\nList sorted by key: " << key << endl << endl;
    cout << "**************** LIST Sorted by Key **********" << endl << endl << endl;
	//Nodeptr p = Table[index];
	Nodeptr p = Table[0];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
            p = Table[i];
        while (p != NULL)
        {
            if (p->stationName == key || p->address == key)		 //if title was found at the index, return Gas Price and index where it was found
            {
                cout << "Gas Station Name: " << p->stationName << endl;
                cout << "Address: " << p->address << endl;
                cout << "Regular Gas Price:" << p->gasPriceRegular << endl;
                cout << "Premium Gas Price:" << p->gasPricePremium << endl;
                cout << "MidGrade Gas Price:" << p->gasPriceMidGrade << endl << endl << endl;
                p = p->next;
                found = true;
            }
            else
                p = p->next;
        }
    }
    if(found == true)
    {
        return 1;
    }
	cout << "Sorry, but " << key << " was not found in the Hash Table.\n\n\n";
	cout << "**************** LIST Sorted by Key End *******" << endl << endl << endl;
	return -1;
}

void HashTable::saveToOutputFile(ofstream &fout)
{
   ifstream fin;
	fin.open("input.txt", ios_base::app);       //opens file and does not overwrite it
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(-1);
	}


    cout << "|-----------------------------------------------------------|\n";  //Display Menu
    cout << "|            SAVE MENU                                      |\n";
    cout << "|                                                           |\n";
    cout << "|   Input file name to save data.                           |\n";
    cout << "|   You could append .txt to the file name you are typing   |\n";
    cout << "|   to make it a .txt file type                             |\n";
    cout << "|                                                           |\n";
    cout << "|-----------------------------------------------------------|\n";

    cout << "Enter file name you want to save to: ";
    string saveName;
    getline(cin, saveName);


	//ofstream fout;
	//fout.open("output.txt");
	fout.open(saveName.c_str());

	if (fout.fail()) {
		cout << "\nsaveToOutputFile(): Output file opening failed.\n";
		exit(-1);
	}
    for(int i = 0; i < TABLE_SIZE; i++)
    {
             Nodeptr p = Table[i];

        if (p->address == "empty")
        {
            //fout << "Index = " << i << " is empty\n";
        }
        else
        {
            while (p != NULL)
            {
                if(!(p->stationName == ""))
                    fout << p->stationName << endl;
                if(!(p->address == ""))
                    fout << p->address << endl;
                if(!(p->gasPriceRegular == NULL))
                    fout << p->gasPriceRegular<< endl;
                if(!(p->gasPricePremium == NULL))
                    fout << p->gasPricePremium << endl;
                if(!(p->gasPriceMidGrade == NULL))
                    fout << p->gasPriceMidGrade << endl;
                p = p->next;
            }
        }
    }
    cout << "\n\nSaved data to " << saveName << " sucessful!!!\n\n";
    fin.close();    //close read file
	fout.close();   //close write file
}
