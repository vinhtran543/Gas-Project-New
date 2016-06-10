/**
Gaseek
* Team 7

* read input into BST: Vinh Tran

* CIS 22C

* BST.cpp

*/

#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void readInputFileBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST)
{
	ifstream fin;
	fin.open("input.txt", ios_base::app);       //opens file and does not overwrite it
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(-1);
	}

	ofstream fout;
	fout.open("outputBST.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(-1);
	}

	while (!fin.eof())   //loops until end of file, until all lines are read from file
	{
		//BST<string> stationNameBST;
		string stationName;
		string fileline;

		getline(fin, fileline);
		stationNameBST.insert(fileline);

		//BST<string> addressBST;
		getline(fin, fileline);
		addressBST.insert(fileline);

		//BST<double> gasPriceRegularBST;
		double gasPriceRegular;
		getline(fin, fileline);
		istringstream iss(fileline);   //converts line in text file to number (double)
		iss >> gasPriceRegular;
		gasPriceRegularBST.insert(gasPriceRegular);

		//BST<double> gasPricePremiumBST;
		double gasPricePremium;
		getline(fin, fileline);
		istringstream iss2(fileline);
		iss2 >> gasPricePremium;
		gasPricePremiumBST.insert(gasPricePremium);

		//BST<double> gasPriceMidGradeBST;
		double gasPriceMidGrade;
		getline(fin, fileline);
		istringstream iss3(fileline);
		iss3 >> gasPriceMidGrade;
		gasPriceMidGradeBST.insert(gasPriceMidGrade);
	}
	//save to output.txt
		stationNameBST.SaveinOrderPrint(fout);
		fout << endl;
		addressBST.SaveinOrderPrint(fout);
		fout << endl;
		gasPriceRegularBST.SaveinOrderPrint(fout);
		fout << endl;
		gasPricePremiumBST.SaveinOrderPrint(fout);
		fout << endl;
		gasPriceMidGradeBST.SaveinOrderPrint(fout);
		fout << endl << endl; //separate the BST when printing to console and to file output.txt

	fin.close();    //close read file
	fout.close();   //close write file

	//return 0;
}
