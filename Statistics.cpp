/**
Gaseek
* Team 7

* Statistics: Dat Pham

* CIS 22C

* Statistics.cpp

*/

#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void Statistics_main(BST<string> &stationNameBST, BST<string> &addressBST, BST<double> &gasPriceRegularBST, BST<double> &gasPricePremiumBST, BST<double> &gasPriceMidGradeBST)
{
    cout << "**************************Statistics**************************" << endl << endl << endl;
    cout << "This is how many Gas Names we have: ";
    cout << stationNameBST.getSize() << endl;
    cout << "This is how many Gas Addresses we have: ";
    cout << addressBST.getSize()<< endl<<endl;

    cout << "This is the total number of how many Regular Gas prices we have: ";
    cout << gasPriceRegularBST.getSize() << endl;
    cout << "This is the total number of how many Premium Gas prices we have: ";
    cout << gasPricePremiumBST.getSize() << endl;
    cout << "This is the total number of how many MidGrade Gas prices we have: ";
    cout << gasPriceMidGradeBST.getSize() << endl << endl;

    cout << "This is the lowest Regular gas price we have: ";
    cout << gasPriceRegularBST.minimum() << endl;
    cout << "This is the lowest Premium gas price we have: ";
    cout << gasPricePremiumBST.minimum() << endl;
    cout << "This is the lowest MidGrade gas price we have: ";
    cout << gasPriceMidGradeBST.minimum() << endl << endl;

    cout << "This is the highest Regular gas price we have: ";
    cout << gasPriceRegularBST.maximum() << endl;
    cout << "This is the highest Premium gas price we have: ";
    cout << gasPricePremiumBST.maximum() << endl;
    cout << "This is the highest MidGrade gas price we have: ";
    cout << gasPriceMidGradeBST.maximum() << endl << endl << endl;
    cout << "**************************Statistics**************************" << endl;

    string selection;

    cout << "Press 1 and Enter to return to Main Menu\n";
    cout << "Enter: ";
    //cin >> selection;
    getline(cin, selection);
    system("CLS");//clear screeen
    return;   //return to Menu before



}
