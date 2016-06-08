/**
Gaseek
* Team 7
Main Menu: Yu-Wei Tseng

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

string mainMenu();

int main()
{
    BST<string> stationNameBST;
    BST<string> addressBST;
    BST<double> gasPriceRegularBST;
    BST<double> gasPricePremiumBST;
    BST<double> gasPriceMidGradeBST;

    ifstream fin;
    ofstream fout;
    HashTable table;
    int choice;

    void readInputFileHashTableMain(HashTable &table);
    readInputFileHashTableMain(table);                    //open input.txt and initialize the table at the start of the program saves HashTable output

    void readInputFileBSTMain(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
    readInputFileBSTMain(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

    do{
        cout << "    Welcome to Gaseek\n\n";
        cout << "\t Menu\n";
        cout << "|-----------------------------------------------|\n";  //Display Menu
        cout << "|           Main Menu                           |\n";
        cout << "|                                               |\n";
        cout << "| 1. Input Data                                 |\n";
        cout << "|                                               |\n";
        cout << "| 2. Delete Data                                |\n";
        cout << "|                                               |\n";
        cout << "| 3. Search Data                                |\n";
        cout << "|                                               |\n";
        cout << "| 4. List Data                                  |\n";
        cout << "|                                               |\n";
        cout << "| 5. Write Data to File                         |\n";
        cout << "|                                               |\n";
        cout << "| 6. Display Statistics                         |\n";
        cout << "|                                               |\n";
        cout << "| 7. Exit                                       |\n";
        cout << "|                                               |\n";
        cout << "|-----------------------------------------------|\n";

        cout << "Please enter a choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
            {
                system("CLS");
                void add(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST, HashTable &table);
                add(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST, table);

            }
        break;
        case 2:
            {
                system("CLS");
                void remove(BST<string> &addressBST, HashTable &table);
                remove(addressBST, table);

            }
        break;
        case 3:
            {
                system("CLS");
                void search(BST<string> &stationNameBST, BST<string> &addressBST);
                search(stationNameBST, addressBST);

            }
        break;
        case 4:
            {
                system("CLS");
                void list(BST<string> &stationNameBST, BST<string> &addressBST,HashTable &table);
                list(stationNameBST, addressBST,table);

            }
        break;
        case 5:
            {
                system("CLS");
                void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
                writeDataToFile(table, stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

            }
        break;
        case 6:
            {
                system("CLS");
                void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
                Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);

            }
        break;
        case 7:
            {
                system("CLS");
                cout << "\n\n\n";
                cout << "Thank you, the program has now closed" << endl;
                cout << "\n\n\n";
                exit(-1);
            }
        break;
        }
    }while(choice != 8);
    /*
    string choice = mainMenu();
    cout << choice << endl;
    if(choice == "1"){
        system("CLS");
        void add(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST, HashTable &table);
        add(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST, table);
        mainMenu();
    }
    else if(choice == "2"){
        system("CLS");
        void remove(BST<string> &addressBST, HashTable &table);

        remove(addressBST, table);
        mainMenu();
    }
    else if(choice == "3"){
        system("CLS");
        void search(BST<string> &stationNameBST, BST<string> &addressBST);
        search(stationNameBST, addressBST);
        mainMenu();
    }
    else if(choice == "4"){
        system("CLS");
        void list(HashTable &table);
        list(table);
        mainMenu();
    }
    else if(choice == "5"){
        system("CLS");
        void writeDataToFile(HashTable &table, BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
        writeDataToFile(table, stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);
        mainMenu();
    }
    else if(choice == "6"){
        system("CLS");
        void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST);
        Statistics_main(stationNameBST, addressBST, gasPriceRegularBST, gasPricePremiumBST, gasPriceMidGradeBST);
        mainMenu();
    }
    else{
        system("CLS");
        cout << "\n\n\n";
        cout << "Thank you, the program has now closed" << endl;
        cout << "\n\n\n";
        exit(-1);
    }
    */
}

/*
string mainMenu()
{
    string choice;
    cout << "    Welcome to Gaseek\n\n";
    cout << "\t Menu\n";
    cout << "|-----------------------------------------------|\n";  //Display Menu
    cout << "|           Main Menu                           |\n";
    cout << "|                                               |\n";
    cout << "| 1. Input Data                                 |\n";
    cout << "|                                               |\n";
    cout << "| 2. Delete Data                                |\n";
    cout << "|                                               |\n";
    cout << "| 3. Search Data                                |\n";
    cout << "|                                               |\n";
    cout << "| 4. List Data                                  |\n";
    cout << "|                                               |\n";
    cout << "| 5. Write Data to File                         |\n";
    cout << "|                                               |\n";
    cout << "| 6. Display Statistics                         |\n";
    cout << "|                                               |\n";
    cout << "| 7. Exit                                       |\n";
    cout << "|                                               |\n";
    cout << "|-----------------------------------------------|\n";

    cout << "Please enter a choice: ";
    //cin >> choice;
    getline(cin, choice);
    if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7"){
        cout << "Invalid input, please try again: ";
        int choiceRe;
        cin >> choiceRe;
    }
    cout << "\n";
    return choice;
}
*/
