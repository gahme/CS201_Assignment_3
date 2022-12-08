#include <string>
#include <iostream>
using namespace std;

#include "MoviesList.h"

MoviesList::MoviesList() {
    head = NULL;
}

MoviesList::~MoviesList() {
    MovieNode *current = head;
    while (current != NULL) {
        MovieNode *temp = current;
        current = current->next;
        delete temp;
    }
}

// Add movie to the list. Do not add if movie already exists and instead print error message
void MoviesList::addMovie( const int movieId, const int numCopies ) {
    if (movieExists(movieId)) {
        cout << "Movie already exists" << endl;
    } else {
        MovieNode *newNode = new MovieNode;
        newNode->movieId = movieId;
        newNode->numCopies = numCopies;
        newNode->numRented = 0;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            MovieNode *current = head;
            MovieNode *previous = NULL;
            while (current != NULL && current->movieId < movieId) {
                previous = current;
                current = current->next;
            }
            if (previous == NULL) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = current;
                previous->next = newNode;
            }
        }
    }
}

// Remove movie from the list. Do not remove if movie does not exist and instead print error message
void MoviesList::removeMovie( const int movieId ) {
    if (!movieExists(movieId)) {
        cout << "Movie " << movieId << " does not exist" << endl;
    } else {
        MovieNode *current = head;
        MovieNode *previous = NULL;
        while (current != NULL && current->movieId < movieId) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            head = head->next;
            delete current;
        } else {
            previous->next = current->next;
            delete current;
            cout << "Movie " << movieId << " has been removed" << endl;
        }
    }
}


// Rent a movie. Do not rent if movie does not exist and instead print error message
void MoviesList::rentMovie( const int movieId ) {
    if (!movieExists(movieId)) {
        cout << "Movie does not exist" << endl;
    } else {
        MovieNode *current = head;
        while (current != NULL && current->movieId < movieId) {
            current = current->next;
        }
        if (current != NULL && current->movieId == movieId) {
            if (current->numCopies == current->numRented) {
                cout << "Movie is not available" << endl;
            } else {
                current->numRented++;
            }
        }
    }
}

// Return a movie. Do not return if movie does not exist and instead print error message
void MoviesList::returnMovie( const int movieId ) {
    if (!movieExists(movieId)) {
        cout << "Movie does not exist" << endl;
    } else {
        MovieNode *current = head;
        while (current != NULL && current->movieId < movieId) {
            current = current->next;
        }
        if (current != NULL && current->movieId == movieId) {
            if (current->numRented == 0) {
                cout << "Movie is not rented" << endl;
            } else {
                current->numRented--;
            }
        }
    }
}

// Show all movies in the list
void MoviesList::showAllMovies() {
    cout << "Movies in the movie rental system:" << endl;
    MovieNode *current = head;
    while (current != NULL) {
        cout << current->movieId << " " << current->numCopies  << endl;
        current = current->next;
    }
}

// Movie exists in the list
bool MoviesList::movieExists( const int movieId ) const{
    MovieNode *current = head;
    while (current != NULL && current->movieId < movieId) {
        current = current->next;
    }
    return (current != NULL && current->movieId == movieId);
}

// Get number of copies of a movie
int MoviesList::getNumCopies( const int movieId ) const{
    MovieNode *current = head;
    while (current != NULL && current->movieId < movieId) {
        current = current->next;
    }
    if (current != NULL && current->movieId == movieId) {
        return current->numCopies;
    } else {
        return 0;
    }
}

// Get number of copies of a movie that are currently rented
int MoviesList::getNumRented( const int movieId ) const{
    MovieNode *current = head;
    while (current != NULL && current->movieId < movieId) {
        current = current->next;
    }
    if (current != NULL && current->movieId == movieId) {
        return current->numRented;
    } else {
        return 0;
    }
}

// Get number of copies of a movie that are currently available
int MoviesList::getNumAvailableCopies( const int movieId ) const{
    MovieNode *current = head;
    while (current != NULL && current->movieId < movieId) {
        current = current->next;
    }
    if (current != NULL && current->movieId == movieId) {
        return current->numCopies - current->numRented;
    } else {
        return 0;
    }
}
