#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie()
{
    this->setMovieCode("");
    this->setMovieName("");
    std::vector<Renter> renters(10);
}


Movie::Movie(string code, string name)
{
    this->setMovieCode(code);
    this->setMovieName(name);
    std::vector<Renter> renters(10);
}

void Movie::setMovieCode(std::string code)
{
    this->movieCode = code;
}

std::string Movie::getMovieCode()
{
    return this->movieCode;
}

void Movie::setMovieName(std::string name)
{
    this->movieName = name;
}

std::string Movie::getMovieName()
{
    return this->movieName;
}

void Movie::rentMovie(Renter s)
{
    if(s.getRenterID()<0)
    {
        throw InvalidRenterIDException();
    }

    //RenterLimitException: Thrown when a renter is renting to a movie without any available copies.
    if(this->renters.size() == 10)
    {
        throw RenterLimitException();
    }

    //DuplicateRenterException: Thrown when trying to add a renter to a movie and a duplicate renter ID exists.
    for(int i = 0; i<this->renters.size(); i++)
    {
        if(this->renters[i].getRenterID() == s.getRenterID())
        {
            throw DuplicateRenterException();   
        }
    }

    this->renters.insert(renters.end(), s);
}

void Movie::returnRental(int renterID)
{

    //EmptyRenterListException: Thrown when trying to return a movie that does not have any copies currently being rented.
    if(this->renters.size() == 0)
    {
        throw EmptyRenterListException();
    }

    //RenterNotFoundException: Thrown when trying to remove a renter for a movie that doesn’t exist.
    bool foundRenter = false;
    for(int i = 0; i<this->renters.size(); i++)
    {
        if(this->renters[i].getRenterID() == renterID)
        {
            foundRenter = true;
            break;
        }
    }

    if(foundRenter == false)
    {
        throw RenterNotFoundException();
    }


    for(int i = 0; i<this->renters.size(); i++)
    {
        if(this->renters[i].getRenterID() == renterID)
        {
            this->renters.erase(this->renters.begin()+i);
        }
    }
}

bool Movie::isBeingRented()
{
    if(this->renters.size() >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printMovieInfo()
{
}


