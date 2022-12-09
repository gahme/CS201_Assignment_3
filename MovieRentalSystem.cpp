#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "MovieRentalSystem.h"


// Constructor for the MovieRentalSystem class. Reads the movie and subscriber information from the files and stores them in the movies and subscribers lists. First line of each file contains the number of movies/subscribers in the file.
MovieRentalSystem::MovieRentalSystem( const string movieInfoFileName, const string subscriberInfoFileName ) {
    ifstream movieFile( movieInfoFileName.c_str() );
    if ( !movieFile ) {
        cout << "Input file " << movieInfoFileName << " does not exist" << endl;
        return;
    }
    int numMovies;
    movieFile >> numMovies;
    for ( int i = 0; i < numMovies; i++ ) {
        int movieId, numCopies;
        movieFile >> movieId >> numCopies;
        movies.addMovie( movieId, numCopies );
    }
    movieFile.close();
    ifstream subscriberFile( subscriberInfoFileName.c_str() );
    if ( !subscriberFile ) {
        cout << "Input file " << subscriberInfoFileName << " does not exist" << endl;
        return;
    }
    int numSubscribers;
    subscriberFile >> numSubscribers;
    for ( int i = 0; i < numSubscribers; i++ ) {
        int subscriberId;
        subscriberFile >> subscriberId;
        subscribers.addSubscriber( subscriberId );
    }
    subscriberFile.close();
    cout << numSubscribers << " subscribers and " << numMovies << " movies have been loaded" << endl;
}

// Destructor for the MovieRentalSystem class.
MovieRentalSystem::~MovieRentalSystem() {
}

// Add a movie to the list of movies. If the movie already exists, print an error message.
void MovieRentalSystem::addMovie( const int movieId, const int numCopies ) {
    if ( movies.movieExists( movieId ) ) {
        cout << "Movie already exists" << endl;
    } else {
        movies.addMovie( movieId, numCopies );
        cout << "Movie " << movieId << " has been added" << endl;
    }
}


// Remove a movie from the list of movies. If the movie does not exist, print an error message. If movie rented by any subscriber, print an error message.
void MovieRentalSystem::removeMovie( const int movieId ) {
    if ( movies.getNumRented( movieId ) > 0 ) {
        cout << "Movie " << movieId << " cannot be removed -- at least one copy has not been returned" << endl;
    } else {
        movies.removeMovie( movieId );
    }
}

// Remove a subscriber from the list of subscribers. If the subscriber does not exist, print an error message. If subscriber has any movies rented, do not remove and print an error message.
void MovieRentalSystem::removeSubscriber( const int subscriberId ) {
    if ( !subscribers.subscriberExists( subscriberId ) ) {
        cout << "Subscriber does not exist" << endl;
    } else if ( subscribers.getNumMoviesRented( subscriberId ) > 0 ) {
        cout << "Subscriber " << subscriberId << " cannot be removed -- at least one movie has not been returned" << endl;
    } else {
        subscribers.removeSubscriber( subscriberId );
        cout << "Subscriber " << subscriberId << " has been removed" << endl;
    }
}

// Rent a movie to a subscriber. If the movie or subscriber does not exist, print an error message. If the movie is not available, print an error message. 
void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId ) {
    if (!movies.movieExists(movieId) and !subscribers.subscriberExists(subscriberId)) {
        cout << "Subscriber " << subscriberId << " and movie " << movieId << " do not exist" << endl;
    } else if ( !movies.movieExists( movieId ) ) {
        cout << "Movie " << movieId << " does not exist" << endl;
    } else if ( !subscribers.subscriberExists( subscriberId )) {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    } else if ( movies.getNumAvailableCopies( movieId ) == 0 ) {
        cout << "Movie " << movieId << " has no available copy for renting" << endl;
    } else {
        movies.rentMovie( movieId );
        subscribers.rentMovie( subscriberId, movieId );
        cout << "Movie " << movieId << " has been rented by subscriber " << subscriberId << endl;
    }
}

// Return a movie from a subscriber. If the movie or subscriber does not exist, print an error message. If the transaction does not exist for subscriber, print an error message. If the movie is already returned, print an error message.
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ) {
    // if (!movies.movieExists(movieId) and !subscribers.subscriberExists(subscriberId)) {
    //     cout << "Subscriber " << subscriberId << " and movie " << movieId << " do not exist" << endl;
    // } else if ( !movies.movieExists( movieId ) ) {
    //     cout << "Movie " << movieId << " does not exist" << endl;
    // } else if ( !subscribers.subscriberExists( subscriberId )) {
    //     cout << "Subscriber " << subscriberId << " does not exist" << endl;
    if ( !subscribers.movieRentedBySubscriber( subscriberId, movieId ) ) {
        cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << endl;
    } else {
        movies.returnMovie( movieId );
        subscribers.returnMovie( subscriberId, movieId );
        cout << "Movie " << movieId << " has been returned by subscriber " << subscriberId << endl;
    }
}

// Show all movies rented by a subscriber. If the subscriber does not exist, print an error message. If the subscriber has no movies rented, print an error message. 
void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) const{
    if ( !subscribers.subscriberExists( subscriberId ) ) {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    } else if ( subscribers.getNumMoviesRented( subscriberId ) == 0 ) {
        cout << "Subscriber " << subscriberId << " has not rented any movies" << endl;
    } else {
        subscribers.showSubscriber( subscriberId );
    }
}

// Show all subscribers renting a movie. If the movie does not exist, print an error message. If no subscriber has rented the movie, print an error message. For each subscriber, print the subscriber id and whether the movie is returned or not.
void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) const{
    if ( !movies.movieExists( movieId ) ) {
        cout << "Movie " << movieId << " does not exist" << endl;
    } else if ( movies.getNumRented( movieId ) == 0 ) {
        cout << "Movie " << movieId << " has not been rented by any subscriber" << endl;
    } else {
        // For each subscriber, print the subscriber id and whether the movie is returned or not.
        subscribers.showSubscribersThatRentedMovie( movieId );
    }
}

// Show all movies.
void MovieRentalSystem::showAllMovies() {
    movies.showAllMovies();
}

// Show all subscribers.
void MovieRentalSystem::showAllSubscribers() {
    subscribers.showAllSubscribers();
}