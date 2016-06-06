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


    //ADD HASH EXAMPLE
    table.addItem("Vinh", "Lay 1991 Avenue", 0.99, 2.99, 1.50);
    table.addItem("Vinh", "Farway 201 Land", 0.99, 2.99, 1.50);
    table.addItem("Bob", "Way 1991 Avenue", 0.99, 2.99, 1.50);
    table.addItem("Great", "1991 Avenue", 0.99, 2.99, 1.50);

    //ADD BST EXAMPLE
    gasPriceMidGradeBST.insert(3.99);

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


    //EXAMPLE STATISTICS FUNCTION Statistics.cpp from BST
    void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    //EXAMPLE SEARCH FUNCTION search.cpp
    void search(BST<string> &stationNameBST, BST<string> &addressBST);
    search(stationNameBST, addressBST);


    //EXAMPLE LIST FUNCTION uses functions from Hash.cpp
    void list(HashTable &table);
    list(table);

    //MENU OPTION WRITE DATA TO FILE FUNCTION
    void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    writeDataToFile(table, stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);


    return 0;
}

