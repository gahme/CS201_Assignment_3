#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "MovieRentalSystem.h"


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

MovieRentalSystem::~MovieRentalSystem() {
}

void MovieRentalSystem::addMovie( const int movieId, const int numCopies ) {
    if ( movies.movieExists( movieId ) ) {
        cout << "Movie already exists" << endl;
    } else {
        movies.addMovie( movieId, numCopies );
        cout << "Movie " << movieId << " has been added" << endl;
    }
}

void MovieRentalSystem::removeMovie( const int movieId ) {
    if ( movies.getNumRented( movieId ) > 0 ) {
        cout << "Movie " << movieId << " cannot be removed -- at least one copy has not been returned" << endl;
    } else {
        movies.removeMovie( movieId );
    }
}

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

void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ) {
    if ( !subscribers.movieRentedBySubscriber( subscriberId, movieId ) ) {
        cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << endl;
    } else {
        movies.returnMovie( movieId );
        subscribers.returnMovie( subscriberId, movieId );
        cout << "Movie " << movieId << " has been returned by subscriber " << subscriberId << endl;
    }
}

void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) const{
    if ( !subscribers.subscriberExists( subscriberId ) ) {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    } else if ( subscribers.getNumMoviesRented( subscriberId ) == 0 ) {
        cout << "Subscriber " << subscriberId << " has not rented any movies" << endl;
    } else {
        subscribers.showSubscriber( subscriberId );
    }
}

void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) const{
    if ( !movies.movieExists( movieId ) ) {
        cout << "Movie " << movieId << " does not exist" << endl;
    } else if ( movies.getNumRented( movieId ) == 0 ) {
        cout << "Movie " << movieId << " has not been rented by any subscriber" << endl;
    } else {
        subscribers.showSubscribersThatRentedMovie( movieId );
    }
}

void MovieRentalSystem::showAllMovies() {
    movies.showAllMovies();
}

void MovieRentalSystem::showAllSubscribers() {
    subscribers.showAllSubscribers();
}