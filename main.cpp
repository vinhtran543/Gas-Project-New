/**
Gaseek
* Team 7
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

using namespace std;

int main()
{
    /////////////////////////////////  INCLUDE THIS AT THE START OF THE PROGRAM    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //INITIALIZE table at START OF PROGRAM with the two functions     void readInputFileHashTableMain() and  void readInputFileHashBucketMain()
    ifstream fin;
    ofstream fout;
    HashTable table;

    void readInputFileHashTableMain(HashTable &table);
    readInputFileHashTableMain(table);                    //open input.txt and initialize the table at the start of the program saves HashTable output
    //table.printTable();

    BST<string> stationNameBST;
    BST<string> addressBST;
    BST<double> gasPriceRegularBST;
    BST<double> gasPricePremiumBST;
    BST<double> gasPriceMidGradeBST;

    void readInputFileBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    readInputFileBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //For ADD FUNCTION Whenever adding to bst or Hash u must ADD to both the BST and HASH and save to both BST and Hash.
    //Example adding a new station name to table. You must also update the BST. So add the new station name to stationNameBST also.
    //Then save

    //MUST CALL THESE FUNCTION BEFORE CLOSING THE PROGRAM
    //SAVE HASH EXAMPLE YOU MUST SAVE TO BOTH (HASH AND BST) WITH THESE COMMANDS AT THE END OF EVERY ADD OR REMOVE (Manipulating DATA)
    table.saveHashTable(fout);
    table.saveHashBucket(fout);


    //SAVE HASH EXAMPLE YOU MUST SAVE TO BOTH (HASH AND BST) WITH THESE COMMANDS AT THE END OF EVERY ADD OR REMOVE (Manipulating DATA)
    void SaveAllBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    SaveAllBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);





    //FUNCTIONS BELOW DO NOT NEED MENU OPTION IMPLEMENTED, ITS ALREADY INCLUDED
    //JUST CALL THESE FUNCTIONS

    //ADD FUNCTION WITH MENU OPTION INCLUDED add.cpp
    void add(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST, HashTable &table);
    add(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST, table);

    //REMOVE FUNCTION WITH MENU INCLUDED remove.cpp
    void remove(BST<string> &addressBST, HashTable &table);
    remove(addressBST, table);

    //SEARCH FUNCTION WITH MENU OPTION INCLUDED search.cpp
    void search(BST<string> &stationNameBST, BST<string> &addressBST);
    search(stationNameBST, addressBST);

    //LIST FUNCTION WITH MENU OPTION INCLUDED uses functions from Hash.cpp
    void list(BST<string> &stationNameBST, BST<string> &addressBST, HashTable &table);
    list(stationNameBST, addressBST,table);

    //EXAMPLE STATISTICS FUNCTION Statistics.cpp from BST
    void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    //WRITE DATA TO FILE WITH MENU OPTION INCLUDED
    void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    writeDataToFile(table, stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    return 0;
}

