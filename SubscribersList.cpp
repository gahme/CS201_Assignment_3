// Ghulam Ahmed - Section 2 - 22101001

#include <string>
#include <iostream>
using namespace std;

#include "SubscribersList.h"

SubscribersList::SubscribersList() {
    head = NULL;
}

SubscribersList::~SubscribersList() {
    SubscriberNode *current = head;
    while (current != NULL) {
        SubscriberNode *temp = current;
        current = current->next;
        delete temp;
    }
}

void SubscribersList::addSubscriber( const int subscriberId ) {
    SubscriberNode *newNode = new SubscriberNode;
    newNode->subscriberId = subscriberId;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        SubscriberNode *current = head;
        SubscriberNode *previous = NULL;
        while (current != NULL && current->subscriberId < subscriberId) {
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

void SubscribersList::removeSubscriber( const int subscriberId ) {
    SubscriberNode *current = head;
    SubscriberNode *previous = NULL;
    while (current != NULL && current->subscriberId < subscriberId) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }
}

void SubscribersList::rentMovie( const int subscriberId, const int movieId ) {
    SubscriberNode *current = head;
    while (current != NULL && current->subscriberId < subscriberId) {
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        current->transactions.addTransaction( movieId );
    }
}

void SubscribersList::returnMovie( const int subscriberId, const int movieId ) {
    SubscriberNode *current = head;
    while (current != NULL && current->subscriberId < subscriberId) {
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        current->transactions.returnMovie( movieId );
    }
}

bool SubscribersList::subscriberExists( const int subscriberId ) const{
    SubscriberNode *current = head;
    while (current != NULL && current->subscriberId < subscriberId) {
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        return true;
    }
    return false;
}

bool SubscribersList::movieRentedToAnySubscriber( const int movieId ) const {
    SubscriberNode *current = head;
    while (current != NULL) {
        if (current->transactions.movieNotReturned( movieId )) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool SubscribersList::movieRentedBySubscriber( const int subscriberId, const int movieId ) const {
    SubscriberNode *current = head;
    while (current != NULL && current->subscriberId < subscriberId) {
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        return current->transactions.movieNotReturned( movieId );
    }
    return false;
}

void SubscribersList::showSubscriber( const int subscriberId ) const {
    SubscriberNode *current = head;
    while (current != NULL && current->subscriberId < subscriberId) {
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        cout << "Subscriber " << current->subscriberId << " has rented the following movies:" << endl;
        current->transactions.showTransactions();
    }
}

void SubscribersList::showAllSubscribers() const {
    cout << "Subscribers in the movie rental system:" << endl;
    SubscriberNode *current = head;
    while (current != NULL) {
        cout << current->subscriberId << endl;
        current = current->next;
    }
}

void SubscribersList::showSubscribersThatRentedMovie( const int movieId ) const {
    SubscriberNode *current = head;
    bool found = false;
    while (current != NULL) {
        if (current->transactions.movieEverRented( movieId )){ 
            if (!found) {
                cout << "Movie " << movieId << " has been rented by the following subscribers:" << endl;
            }
            found = true;
            for (int i = 0; i < current->transactions.getNumMoviesTransactions(movieId); i++){
                if (current->transactions.movieNotReturned( movieId )) {
                    cout << current->subscriberId << " not returned" << endl;
                } else {
                    cout << current->subscriberId << " returned" << endl;
                }
            }
        }
        current = current->next;
    }
}

int SubscribersList::getNumMoviesRented( const int subscriberId ) const {
    SubscriberNode *current = head;
    while (current != NULL && current->subscriberId < subscriberId) {
        current = current->next;
    }
    if (current != NULL && current->subscriberId == subscriberId) {
        return current->transactions.getNumMoviesNotReturned();
    }
    return 0;
}
