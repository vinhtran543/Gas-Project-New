/**
Gaseek
* Team 7
Vinh Tran

* CIS 22C

* HashTable.h

*/
#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class HashTable {

public:
	HashTable();

	~HashTable();
	//Destructor

	int hash(string key);
	//returns the hash value for the given key
	//the hash value is the sum of
	//the ASCII values of each character % the table size

	void addItem(string stationName, string address, double gasPriceRegular, double gasPricePremium, double gasPriceMidGrade);
	//inserts a new item into the table
	// calls the hash function on the key title to determine the correct bucket

	void removeItem(string key);
	//removes the item with the given key

	int numItemsAtIndex(int index);
	//Helper function to printTable
	//Counts the number of items in each bucket

	void printTable();
	//prints the first item of each bucket
	//includes the number of items stored at that bucket

	void saveHashTable(ofstream &fout);   //saves to output text

	void printBucket(int index);
	//Prints all items stored at a single bucket

	void saveHashBucket(ofstream &fout);   //save to output text

	int listGasPrice(string key);
	//Searches for an author in the table using the key
	//returns the index under which the author is stored
	//returns -1 if the author is not found

	void saveToOutputFile(ofstream &fout);



private:

	struct Node
	{
		string stationName;
		string address;
		double gasPriceRegular;
		double gasPricePremium;
		double gasPriceMidGrade;

		Node* next;

		Node() : stationName(""), address(""), gasPriceRegular(0), gasPricePremium(0), gasPriceMidGrade(0), next(NULL){}
		Node(string nstationName, string naddress, double ngasPriceRegular, double ngasPricePremium, double ngasPriceMidGrade) : stationName(nstationName), address(naddress),
			gasPriceRegular(ngasPriceRegular), gasPricePremium(ngasPricePremium), gasPriceMidGrade(ngasPriceMidGrade), next(NULL) {}
	};

	typedef struct Node* Nodeptr;

	static const int TABLE_SIZE = 50;
	Nodeptr Table[TABLE_SIZE];

};

#endif /* HASHTABLE_H_ */



