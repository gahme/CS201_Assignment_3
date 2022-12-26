// Ghulam Ahmed - Section 2 - 22101001

#include "TransactionsList.h"

class SubscribersList{
    public:
        SubscribersList();
        ~SubscribersList();
        void addSubscriber( const int subscriberId );
        void removeSubscriber( const int subscriberId );
        void rentMovie( const int subscriberId, const int movieId );
        void returnMovie( const int subscriberId, const int movieId );
        bool subscriberExists( const int subscriberId ) const;
        bool movieRentedBySubscriber( const int subscriberId, const int movieId ) const;
        void showSubscriber( const int subscriberId ) const;
        void showAllSubscribers() const;
        void showSubscribersThatRentedMovie( const int movieId ) const;
        int getNumMoviesRented( const int subscriberId ) const;
    private:
        struct SubscriberNode {
            int subscriberId;
            SubscriberNode *next;
            TransactionsList transactions;
        };
        SubscriberNode *head;
};
