#include "Renter.h"
using namespace std;

Renter::Renter()
{
    this->setRenterID(0);
    this->setRenterFirstName("");
    this->setRenterLastName("");
}


Renter::Renter(int ID, std::string firstName, std::string lastName)
{
    this->setRenterID(ID);
    this->setRenterFirstName(firstName);
    this->setRenterLastName(lastName);
}


void Renter::setRenterID(int id)
{
    this->renterID = id;
}


int Renter::getRenterID()
{
    return this->renterID;
}


void Renter::setRenterFirstName(std::string fName)
{
    this->renterFirstName = fName;
}


std::string Renter::getRenterFirstName()
{
    return this->renterFirstName;
}


void Renter::setRenterLastName(std::string lName)
{
    this->renterLastName = lName;
}


std::string Renter::getRenterLastName()
{
    return this->renterLastName;
}