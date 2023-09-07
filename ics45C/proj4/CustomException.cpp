#include "CustomException.h"

const char* DuplicateMovieException::what()
{
    return "A movie already exists when trying to add a new movie";
}


const char* DuplicateRenterException::what()
{
    return "Trying to add a renter to a movie and a duplicate renter ID exists";
}


const char* EmptyMovieInfoException::what()
{
    return "The movie code and/or movie name is empty when trying to add one to the movie array";   
}


const char* EmptyMovieListException::what()
{
    return "Trying to discontinue a movie when the inventory list is empty";
}


const char* EmptyRenterListException::what()
{
    return "Trying to return a movie that does not have any copies currently being rented";
}


const char* EmptyRenterNameException::what()
{
    return "The user entered an empty first and/or last name for the renter";
}


const char* InvalidRenterIDException::what()
{
    return "The user entered an invalid renter ID";
}


const char* MovieLimitException::what()
{
    return "A movie is trying to be added and the number of movies is at the at the max";
}


const char* MovieNotFoundException::what()
{
    return "Trying to do something with movie that does not exist";
}


const char* RentedMovieException::what()
{
    return "The user attempts to discontinue a movie that has copies currently rented out";
}


const char* RenterLimitException::what()
{
    return "A renter is renting to a movie without any available copies";
}


const char* RenterNotFoundException::what()
{
    return "Trying to remove a renter for a movie that doesn't exist";
}