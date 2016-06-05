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

    //SAVES TO OUTPUT FILE
    table.saveHashBucket(fout);
    //table.printBucket(4);

    BST<string> stationNameBST;
    BST<string> addressBST;
    BST<double> gasPriceRegularBST;
    BST<double> gasPricePremiumBST;
    BST<double> gasPriceMidGradeBST;

    void readInputFileBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    readInputFileBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);
    //gasPriceRegularBST.inOrderPrint();
    //cout << gasPriceRegularBST.minimum();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //ADD HASH EXAMPLE
    table.addItem("Vinh", "Lay 1991 Avenue", 0.99, 2.99, 1.50);
    table.addItem("Vinh", "Farway 201 Land", 0.99, 2.99, 1.50);
    table.addItem("Bob", "Way 1991 Avenue", 0.99, 2.99, 1.50);
    table.addItem("Great", "1991 Avenue", 0.99, 2.99, 1.50);


  //stationNameBST.inOrderPrint();


    //SAVE HASH EXAMPLE
    table.saveHashTable(fout);
    table.saveHashBucket(fout);

    //ADD BST EXAMPLE
    gasPriceMidGradeBST.insert(3.99);

    //SAVE BST EXAMPLE
    void SaveAllBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    SaveAllBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    //EXAMPLE STATISTICS FUNCTION Statistics.cpp from BST
    void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    //EXAMPLE SEARCH FUNCTION search.cpp
    void search(BST<string> &stationNameBST, BST<string> &addressBST);
    search(stationNameBST, addressBST);


    //EXAMPLE LIST FUNCTION uses functions from Hash.cpp
    //table.listGasPrice("1709 Automation Pkwy");
    //table.listGasPrice("Rotten Robbie");

    return 0;
}

