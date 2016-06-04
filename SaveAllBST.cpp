/**
Gaseek
* Team 7
Dat Pham

* CIS 22C

* SaveALLBST.cpp

*/

#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void SaveAllBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST)
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
}

