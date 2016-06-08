/**
Gaseek
* Team 7
List Sort: Vinh Tran,
Menus: Yu Wei Tseng

* CIS 22C

* list.cpp

*/
#include "HashTable.h";
#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void list(BST<string> &stationNameBST, BST<string> &addressBST, HashTable &table)
{

    int selection;
    string choice;

    do
    {
        cout << "\n\n\n****** Please select an option 1 through 4 *****\n\n\n";
        cout << "|-----------------------------------------------|\n";  //Display Menu
        cout << "|            List Data MENU                     |\n";
        cout << "|                                               |\n";
        cout << "| 1. List Unsorted Data                         |\n";
        cout << "|                                               |\n";
        cout << "| 2. List by Primary Key: Gas Station Address   |\n";
        cout << "|                                               |\n";
        cout << "| 3. List by Secondary Key: Gas Station Name    |\n";
        cout << "|                                               |\n";
        cout << "| 4. Exit                                       |\n";
        cout << "|-----------------------------------------------|\n";
        cout << "Enter selection : ";
        int selection;
        cin >> selection;
        cin.ignore();
        system("CLS");//clear screeen

        switch(selection)
        {
            case 1:
            {
                //SEARCH GASPRICE EXAMPLE with PRIMARY KEY(address) and SECONDARY KEY(stationName) uses BST

                cout << "********** List Unsorted Data ***********\n\n";

                table.printTable();

                cout << "********* List Unsorted Data End **********\n\n";
            }
            break;

            case 2:
            {
                cout << "********** List Primary Sorted Data *************\n\n";

                cout << "Here are all the gas station addresses to choose from:\n\n";
                addressBST.inOrderPrint();

                string key;
                cout << "Enter station address key to search\n";
                cout << "through the primary sorted Hash data\n\n";

                cout << "Enter station address: ";
                getline(cin, key);
                table.listGas(key);

                cout << "********** List Primary Sorted End **************\n\n\n";
            }
            break;

            case 3:
            {
                cout << "********** List Secondary Sorted Data ***********\n\n";

                cout << "Here are all the gas station addresses to choose from:\n\n";
                stationNameBST.inOrderPrint();
                string key2;
                cout << "Enter station name key to search\n";
                cout << "through the secondary sorted Hash data\n\n";

                cout << "Enter station name: ";
                getline(cin, key2);
                table.listGas(key2);

                cout << "********** List Secondary Sorted End ***********\n\n\n";
            }
            break;

            case 4:
            {
                return;  //Return to Menu Before
            }
        }
    }while(selection != 4);

    return;
}
