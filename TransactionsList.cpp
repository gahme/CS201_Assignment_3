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
        while (current != NULL && current->movieId <= movieId) {
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
}

void TransactionsList::returnMovie( const int movieId ) {
    TransactionNode *current = head;
    while (current != NULL && current->movieId <= movieId) {
        if (current->movieId == movieId && !current->returned) {
            current->returned = true;
            break;
        }
        current = current->next;
    }
}

bool TransactionsList::movieNotReturned( const int movieId ) const {
    TransactionNode *current = head;
    bool found = false;
    while (current != NULL && current->movieId <= movieId) {
        if (current->movieId == movieId && !current->returned) {
            found = true;
        }
        current = current->next;
    }
    return found;
}

bool TransactionsList::movieEverRented( const int movieId ) const {
    TransactionNode *current = head;
    bool found = false;
    while (current != NULL && current->movieId <= movieId) {
        if (current->movieId == movieId) {
            found = true;
        }
        current = current->next;
    }
    return found;
}

int TransactionsList::getNumMoviesTransactions(const int movieId) const {
    TransactionNode *current = head;
    int count = 0;
    while (current != NULL && current->movieId <= movieId) {
        if (current->movieId == movieId) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int TransactionsList::getNumMoviesNotReturned() const {
    TransactionNode *current = head;
    int count = 0;
    while (current != NULL) {
        if (!current->returned) {
            count++;
        }
        current = current->next;
    }
    return count;
}