#include "MovieManager.h"
#include "MovieManagerUI.h"
#include <iostream>

using namespace std;

MovieManagerUI mmUI;

std::vector<Movie> movies(20);

void run()
{
    try
    {
        mmUI.printMenu();
        mmUI.getCommand();
    }
    
    catch(DuplicateMovieException& e)
    {
        e.what();
    }

    catch(DuplicateRenterException& e)
    {
        e.what();
    }

    catch(EmptyMovieInfoException& e)
    {
        e.what();
    }

    catch(EmptyMovieListException& e)
    {
        e.what();
    }

    catch(EmptyRenterListException& e)
    {
        e.what();
    }

    catch(EmptyRenterNameException& e)
    {
        e.what();
    }

    catch(InvalidRenterIDException& e)
    {
        e.what();
    }

    catch(MovieLimitException& e)
    {
        e.what();
    }

    catch(MovieNotFoundException& e)
    {
        e.what();
    }

    catch(RentedMovieException& e)
    {
        e.what();
    }

    catch(RenterLimitException& e)
    {
        e.what();
    }

    catch(RenterNotFoundException& e)
    {
        e.what();
    }
}


void MovieManager::addMovie(Movie m)
{
    if(this->movies.size() == 20)
    {
        //Thrown when a movie is trying to be added and the number of movies is at the at the max (I.e. 20)
        throw MovieLimitException();
    }

    //Thrown when the movie code and/or movie name is empty when trying to add one to the movie array
    if(m.getMovieCode() == "" || m.getMovieName() == "")
    {
        throw EmptyMovieInfoException();
    }

    //Thrown when a movie already exists when trying to add a new movie
    for(int i = 0; i<this->movies.size(); i++)
    {
        if(this->movies[i].getMovieCode() == m.getMovieCode())
        {
            throw DuplicateMovieException();
        }
    }


    this->movies.insert(movies.end(), m);
    
}

void MovieManager::discontinueMovie(std::string movieCode)
{

    //EmptyMovieListException: Thrown when trying to discontinue a movie when the inventory list is empty.
    if(this->movies.size() == 0)
    {
        throw EmptyMovieListException();
    }

    //MovieNotFoundException: Thrown when trying to do something with movie that does not exist
    bool foundCode = false;
    for(int i = 0; i<this->movies.size(); i++)
    {
        if(this->movies[i].getMovieCode() == movieCode)
        {
            foundCode = true;
            break;
        }
    }

    if(foundCode == false)
    {
        throw MovieNotFoundException();
    }

    //RentedMovieException: Thrown when the user attempts to discontinue a movie that has copies currently rented out
    for(int i = 0; i<this->movies.size(); i++)
    {
        if(this->movies[i].getMovieCode() == movieCode)
        {
            if(movies[i].isBeingRented() == true)
            {
                throw RentedMovieException();
            }
        }
    }


    for(int i = 0; i<this->movies.size(); i++)
    {
        if(this->movies[i].getMovieCode() == movieCode)
        {
            this->movies.erase(this->movies.begin()+i);
        }
    }
}


void MovieManager::rentMovie(std::string movieCode, Renter s)
{
    //MovieNotFoundException: Thrown when trying to do something with movie that does not exist
    bool foundCode = false;
    for(int i = 0; i<this->movies.size(); i++)
    {
        if(this->movies[i].getMovieCode() == movieCode)
        {
            foundCode = true;
            break;
        }
    }

    if(foundCode == false)
    {
        throw MovieNotFoundException();
    }


    //EmptyRenterNameException: Thrown when the user enters an empty first and/or last name for the renter.
    if(s.getRenterFirstName() == "" || s.getRenterLastName() == "")
    {
        throw EmptyRenterNameException();
    }


    /*InvalidRenterIDException: Thrown when the user enters an invalid renter ID.
    if(s.getRenterID() < 0)
    {
        throw InvalidRenterIDException();
    }

    for(int j = 0; j<this->movies.size(); j++)
    {
        if(this->movies[j].getMovieCode() == movieCode)
        {
            for(int k = 0; k<movies[j].renters.size(); k++)
            {
                if(movies[j].renters[k].getRenterID() == s.getRenterID())
                {
                    throw InvalidRenterIDException();
                }
            }
        }
    }*/


    for(int i = 0; i<this->movies.size(); i++)
    {
        if(movies[i].getMovieCode() == movieCode)
        {
            this->movies[i].rentMovie(s);
        }
    }
}


void MovieManager::returnRental(int renterID, std::string mCode)
{

    /*EmptyRenterListException: Thrown when trying to return a movie that does not have any copies currently being rented
    for(int i = 0; i<this->movies.size(); i++)
    {
        if(movies[i].getMovieCode() == mCode)
        {
            if(this->movies[i].renters.size() == 0)
            {
                throw EmptyRenterListException();
            }
        }
    }*/


    //MovieNotFoundException: Thrown when trying to do something with movie that does not exist
    bool foundCode = false;
    for(int i = 0; i<this->movies.size(); i++)
    {
        if(this->movies[i].getMovieCode() == mCode)
        {
            foundCode = true;
            break;
        }
    }

    if(foundCode == false)
    {
        throw MovieNotFoundException();
    }


    //InvalidRenterIDException: Thrown when the user enters an invalid renter ID.
    if(renterID < 0)
    {
        throw InvalidRenterIDException();
    }

    /*bool foundID = false;
    for(int j = 0; j<this->movies.size(); j++)
    {
        if(this->movies[j].getMovieCode() == mCode)
        {
            for(int k = 0; k<movies[j].renters.size(); k++)
            {
                if(movies[j].renters[k].getRenterID() == renterID)
                {
                    foundID = true;
                    break;
                }
            }
        }
    }

    if(foundID == false)
    {
        throw InvalidRenterIDException();
    }*/


    for(int i = 0; i<this->movies.size(); i++)
    {
        if(movies[i].getMovieCode() == mCode)
        {
            this->movies[i].returnRental(renterID);
        }
    }
}

void MovieManager::printInventory()
{
    for(int i = 0; i<this->movies.size(); i++)
    {
        cout << "Name: " << this->movies[i].getMovieName() << endl;
        cout << "Movie Code: " << this->movies[i].getMovieCode() << endl;
        
        //Info about renters
        for(int j = 0; j<this->movies[i].renters.size(); j++)
        {
            cout << "Renter " << j << ": " << movies[i].renters[j].getRenterFirstName() << " " << movies[i].renters[j].getRenterLastName() << endl;
            cout << "Renter ID: " << movies[i].renters[j].getRenterID() << endl;
        }
    }
}