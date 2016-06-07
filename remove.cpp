/**
Gasseek

* remove: Min
Menus: Yu Wei Tseng
* Team 7

* CIS 22C

* Add.cpp

*/
#include "BST.h";
#include "HashTable.h";
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
 using namespace std;



void remove(BST<string> &addressBST, HashTable &table)
{
    int selection;
    string choice;

    do
    {
        cout << "\n\n\n****** Please select an option 1 or 2 *****\n\n\n";
        cout << "|-----------------------------------------------|\n";  //Display Menu
        cout << "|            Remove MENU                        |\n";
        cout << "|                                               |\n";
        cout << "| 1. Remove Data                                |\n";
        cout << "|                                               |\n";
        cout << "| 2. Exit To Main Menu                          |\n";
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
                cout <<"\n\n\n*************************Remove GAS DATA ***********************************\n\n\n";
                cout << "Enter the Station Address that you would like to remove." << endl << endl;
                cout << "Enter station address: ";
                string address;
                getline(cin, address);



                table.removeItem(address);

                addressBST.remove(address);


                cout <<"\n\n\n*************************REMOVE GAS DATA END ***********************************\n\n\n";
            }
            break;

            case 2:
                {
                    return;
                }
                break;
    }
    }
    while (selection != 2);
    return;
}

