/**
Gaseek
* Team 7
Min and Vinh Tran

* CIS 22C

* writeDataToFile.cpp

*/
#include "HashTable.h";
#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST)
{
    ofstream fin;
    ofstream fout;

     //MUST CALL THESE FUNCTION BEFORE CLOSING THE PROGRAM//

    //SAVE HASH EXAMPLE YOU MUST SAVE TO BOTH (HASH AND BST) WITH THESE COMMANDS AT THE END OF EVERY ADD OR REMOVE (Manipulating DATA)
    table.saveHashTable(fout);
    table.saveHashBucket(fout);


    //SAVE HASH EXAMPLE YOU MUST SAVE TO BOTH (HASH AND BST) WITH THESE COMMANDS AT THE END OF EVERY ADD OR REMOVE (Manipulating DATA)
    void SaveAllBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    SaveAllBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);



    cout << "***********  SAVING TO OUTPUT FILE *********************\n\n";
    cout << endl;

    table.saveToOutputFile(fout);

    cout << endl << endl;
    cout << "***********  SAVING TO OUTPUT FILE END *****************\n\n";

    cout << "Press 1 to return to Main Menu\n";
    cout << "Enter: ";
    int selection;
    cin >> selection;
    system("CLS");//clear screeen
    return;
}
