// Ghulam Ahmed - Section 2 - 22101001

#include "TransactionsList.h"

// Sorted link list of subscribers
class SubscribersList{
    public:
        SubscribersList();
        ~SubscribersList();
        void addSubscriber( const int subscriberId );
        void removeSubscriber( const int subscriberId );
        void rentMovie( const int subscriberId, const int movieId );
        void returnMovie( const int subscriberId, const int movieId );
        bool subscriberExists( const int subscriberId ) const;
        bool movieRentedToAnySubscriber( const int movieId ) const;
        bool movieRentedBySubscriber( const int subscriberId, const int movieId ) const;
        void showSubscriber( const int subscriberId ) const;
        void showAllSubscribers() const;
        int getNumMoviesRented( const int subscriberId ) const;
    private:
        struct SubscriberNode {
            int subscriberId;
            SubscriberNode *next;
            TransactionsList transactions;
        };
        SubscriberNode *head;
};
