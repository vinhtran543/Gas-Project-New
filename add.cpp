/**
Gasseek
* Team 7

* add: Jimmy Le

* Menus: Yu Wei Tseng

* CIS 22C

* Add.cpp

*/
#include "HashTable.h"
#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void add(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST, HashTable &table)
{
    int selection;
    string choice;

    do
    {
        cout << "\n\n\n****** Please select an option 1 or 2 *****\n\n\n";
        cout << "|-----------------------------------------------|\n";  //Display Menu
        cout << "|            Add MENU                           |\n";
        cout << "|                                               |\n";
        cout << "| 1. Add Data                                   |\n";
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
                cout <<"\n\n\n*************************ADD GAS DATA ***********************************\n\n\n";
                cout << "Enter the Station Address that you would like to add." << endl << endl;
                cout << "Enter station address: ";
                string address;
                getline(cin, address);

                cout << "\nEnter the Station Name you would like to add." << endl << endl;
                cout << "Enter station name: ";
                string stationName;
                getline(cin, stationName);

                cout << "\nEnter the Gas Prices by this order; Regular, Premium, Midgrade" << endl << endl;
                cout << "Enter regular gas price: ";
                string input;
                getline(cin, input);
                istringstream iss(input);
                double gasPriceRegular;
                iss >> gasPriceRegular;

                string input2;
                cout << "\nEnter premium gas price: ";
                getline(cin, input2);
                istringstream iss2(input2);
                double gasPricePremium;
                iss2 >> gasPricePremium;

                string input3;
                cout << "\nEnter midgrade gas price: ";
                getline(cin, input3);
                istringstream iss3(input3);
                double gasPriceMidGrade;
                iss3 >> gasPriceMidGrade;

                table.addItem( stationName,  address, gasPriceRegular, gasPricePremium, gasPriceMidGrade);

                addressBST.insert(address);
                stationNameBST.insert(stationName);
                gasPriceRegularBST.insert(gasPriceRegular);
                gasPricePremiumBST.insert(gasPricePremium);
                gasPriceMidGradeBST.insert(gasPriceMidGrade);

                cout << "\n\nSuccessfully added data!!!\n";

                cout <<"\n\n\n*************************ADD GAS DATA END ***********************************\n\n\n";
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

