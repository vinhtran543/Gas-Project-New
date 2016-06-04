/**
Gaseek
* Team 7
Min
* CIS 22C

* main.cpp

*/

#include "HashTable.h"
#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

void readInputFileHashTableMain(HashTable &table)
{
    ifstream fin;
	fin.open("input.txt", ios_base::app);       //opens file and does not overwrite it
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(-1);
	}

	ofstream fout;
	fout.open("outputHashTablePrint.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(-1);
	}


	//HashTable table;

	while (!fin.eof())   //loops until end of file, until all lines are read from file
	{

		string fileline;
		getline(fin, fileline);
		string stationName = fileline;

		getline(fin, fileline);
		string address = fileline;

		getline(fin, fileline);
		istringstream iss(fileline);
		double gasPriceRegular;
		iss >> gasPriceRegular;

		getline(fin, fileline);
		istringstream iss2(fileline);
		double gasPricePremium;
		iss2 >> gasPricePremium;

		getline(fin, fileline);
		istringstream iss3(fileline);
		double gasPriceMidGrade;
		iss3 >> gasPriceMidGrade;

		table.addItem(stationName, address, gasPriceRegular, gasPricePremium, gasPriceMidGrade);
	}
	table.saveHashTable(fout);   //saves to output file
	fin.close();    //close read file
	fout.close();   //close write file
}
