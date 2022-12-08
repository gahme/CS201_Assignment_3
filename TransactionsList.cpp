// Ghulam Ahmed - Section 2 - 22101001

#include <string>
#include <iostream>
using namespace std;

#include "TransactionsList.h"

TransactionsList::TransactionsList() {
    head = NULL;
}

TransactionsList::~TransactionsList() {
    TransactionNode *current = head;
    while (current != NULL) {
        TransactionNode *temp = current;
        current = current->next;
        delete temp;
    }
}

void TransactionsList::addTransaction( const int movieId ) {
    TransactionNode *newNode = new TransactionNode;
    newNode->movieId = movieId;
    newNode->returned = false;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        TransactionNode *current = head;
        TransactionNode *previous = NULL;
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
    transactionCount++;
}


void TransactionsList::showTransactions() const {
    TransactionNode *current = head;
    while (current != NULL) {
        if (current->returned) {
            cout << current->movieId << " returned" << endl;
        } else {
            cout << current->movieId << " not returned" << endl;
        }
        current = current->next;
    }
    cout << endl;
}

// void TransactionsList::returnMovie( const int movieId ) {
//     TransactionNode *current = head;
//     while (current != NULL && current->movieId < movieId) {
//         current = current->next;
//     }
//     if (current != NULL && current->movieId == movieId) {
//         if (current->returned) {
//             cout << "Movie " << movieId << " has already been returned." << endl;
//         } else {
//             current->returned = true;
//         }
//     }
// }

// Return movie if it is rented. Just set the returned flag to true.
// If the movie is not rented, do nothing.
void TransactionsList::returnMovie( const int movieId ) {
    TransactionNode *current = head;
    while (current != NULL && current->movieId < movieId) {
        current = current->next;
    }
    if (current != NULL && current->movieId == movieId) {
        current->returned = true;
    }
}

bool TransactionsList::movieRented( const int movieId ) const{
    TransactionNode *current = head;
    while (current != NULL && current->movieId < movieId) {
        current = current->next;
    }
    return (current != NULL && current->movieId == movieId);
}

int TransactionsList::getNumTransactions() const{
    return transactionCount;
}