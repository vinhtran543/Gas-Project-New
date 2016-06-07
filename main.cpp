/*
Gaseek
* Team 7
* CIS 22C

* main.cpp


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
    void list(HashTable &table);
    list(table);

    //EXAMPLE STATISTICS FUNCTION Statistics.cpp from BST
    void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    //WRITE DATA TO FILE WITH MENU OPTION INCLUDED
    void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    writeDataToFile(table, stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    return 0;
}
*/

/**
Gaseek
* Team 7

* CIS 22C

* ProjectTest.cpp

*/

#include "BST.h"
#include "HashTable.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

int mainMenu()
{
    int choice;
    cout << "    Welcome to Gaseek\n\n";
    cout << "\t Menu\n";
    cout << "--------------------------" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Delete Data" << endl;
    cout << "3. Search Data" << endl;
    cout << "4. List Data" << endl;
    cout << "5. Write Data to File" << endl;
    cout << "6. Display Statistics" << endl;
    cout << "7. Exit\n" << endl;
    cout << "--------------------------" << endl;
    cout << "Please enter a choice: ";
    cin >> choice;
    if(choice != 1 && choice != 2 && choice != 3 && choice !=4 && choice != 5 && choice != 6){
        cout << "Invalid input, please try again: ";
        int choiceRe;
        cin >> choiceRe;
    }
    cout << "\n";
    return choice;
}

void inputDataMenu()
{
    void add(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST, HashTable &table);
    add(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST, table);
    mainMenu();
}

void deleteDataMenu()
{
    void remove(BST<string> &addressBST, HashTable &table);
    mainMenu();
}

void searchMenu()
{
    void search(BST<string> &stationNameBST, BST<string> &addressBST);
    search(stationNameBST, addressBST);
}

void listDataMenu()
{
    void list(HashTable &table);
    list(table);
}

void writeToFileMenu()
{
    
    void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    writeDataToFile(table, stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);
    
}

void displayStats()
{
    
    void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);
    
}

int main()
{
    ifstream fin;
    ofstream fout;
    HashTable table;

    void readInputFileHashTableMain(HashTable &table);
    readInputFileHashTableMain(table);                    //open input.txt and initialize the table at the start of the program saves HashTable output

    BST<string> stationNameBST;
    BST<string> addressBST;
    BST<double> gasPriceRegularBST;
    BST<double> gasPricePremiumBST;
    BST<double> gasPriceMidGradeBST;

    void readInputFileBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    readInputFileBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    
    int choice = mainMenu();
    if(choice == 1){
        system("CLS");
        inputDataMenu();
    }
    else if(choice == 2){
        system("CLS");
        deleteDataMenu();
    }
    else if(choice == 3){
        searchMenu();
    }
    else if(choice == 4){
        listDataMenu();
    }
    else if(choice == 5){
        writeToFileMenu();
    }
    else if(choice == 6){
        displayStats();
    }
    else{
        exit(-1);
    }
}



