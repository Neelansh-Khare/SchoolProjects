#include "MovieManagerUI.h"
#include <iostream>
#include <cstring>

using namespace std;

std::string MovieManagerUI::toUpper(std::string str1){
    return toUpper(str1);
}

//Prints menu
void MovieManagerUI::printMenu(){
    std::cout << "am: Add Movie" << endl;
    std::cout << "dm: Discontinue Movie" << endl;
    cout << "rm: Rent Movie" << endl;
    cout << "rr: Return Rental" << endl;
    cout << "p: Print Movie Inventory" << endl;
    cout << "q: Quit Program" << endl;
    cout << "----------" << endl;
    cout << "Enter Command:" << endl;
}


//Gets command from user and loops until valid input
string MovieManagerUI::getCommand()
{
    std::string x;
    cin >> x;

    string upper = this->toUpper(x);
    
    while(upper != "AM" && upper !="DM" && upper != "RM" && upper != "RR" && upper != "P" && upper != "Q")
    {
        cin >> x;
    }

    return x;
}


std::string getMovieName()
{
    string str1;
    cout << "Enter movie name: ";
    cin >> str1;
    return str1;
}


std::string getMovieCode()
{
    string strCode;
    cout << "Enter movie code: ";
    cin >> strCode;
    return strCode;
}


int getRenterID()
{
    int rID;
    cout << "Enter renter ID: ";
    cin >> rID;
    return rID;
}


std::string getRenterFirstName()
{
    string rFirst;
    cout << "Enter Renter First Name: ";
    cin >> rFirst;
    return rFirst;
}


std::string getRenterLastName()
{
    string rLast;
    cout << "Enter Renter Last Name: ";
    cin >> rLast;
    return rLast;
}


void MovieManagerUI::invalidSelection()
{
    cout << "Invalid command" << endl;
}

void enterToContinue()
{
    cout << "Enter to continue: " << endl;
}


void print(std::string s) 
{
    cout << s;
}