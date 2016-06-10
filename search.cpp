/**
Gaseek
* Team 7

* Search: Vinh Tran

* Menus: Yu Wei Tseng

* CIS 22C

* search.cpp

*/

#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void search(BST<string> &stationNameBST, BST<string> &addressBST)
{

    int selection;
    string choice;

    do
    {
        cout << "\n\n\n****** Please select an option 1 through 3 *****\n\n\n";
        cout << "|-----------------------------------------------|\n";  //Display Menu
        cout << "|            Search MENU                        |\n";
        cout << "|                                               |\n";
        cout << "| 1. Search by Primary Key: Gas Station Address |\n";
        cout << "|                                               |\n";
        cout << "| 2. Search by Secondary Key: Gas Station Name  |\n";
        cout << "|                                               |\n";
        cout << "| 3. Back to Main Menu                          |\n";
        cout << "|                                               |\n";
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

                cout << "\n\n\n********** SEARCH PRIMARY SORTED: GAS STATION ADDRESS ***********\n\n";

                cout << "Here are all the gas station addresses to choose from:\n\n";
                addressBST.inOrderPrint();

                cout << "Enter address to search through the primary sorted BST data\n";
                string key;
                cout << "Enter station address: ";
                getline(cin, key);
                //cin.ignore(100, '\n');

                addressBST.searchAddress(key);
                cout << endl;

                cout << "*************** SEARCH PRIMARY SORTED: GAS STATION ADDRESS ************\n\n\n";

                //cout << "Press 1 to search again, Press 2 to go back to Search Menu\n";
                //cout << "Enter: ";
                //cin >> choice;
            }
            break;

            case 2:
            {
                cout << "\n\n\n********** SEARCH SECONDARY SORTED: GAS STATION NAME ***********\n\n";

                cout << "Here are all the gas station addresses to choose from:\n\n";
                stationNameBST.inOrderPrint();

                string key2;
                cout << "Enter station Name key to search through the secondary sorted BST data\n\n";

                cout << "Enter station name: ";
                getline(cin, key2);


                stationNameBST.searchStation(key2, stationNameBST);
                cout << endl;

                cout << "************** SEARCH SECONDARY SORTED: GAS STATION NAME **********\n\n\n";
            }
            break;

            case 3:
            {
                 return;  //Return to Menu Before
            }

        }
    }while(selection != 3);

    return;
}
