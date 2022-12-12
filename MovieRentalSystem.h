// Ghulam Ahmed - Section 2 - 22101001

#include <string>
#include "MoviesList.h"
#include "SubscribersList.h"
using namespace std;

class MovieRentalSystem {
    public:
        MovieRentalSystem( const string movieInfoFileName, const string subscriberInfoFileName );
        ~MovieRentalSystem();
        void removeMovie( const int movieId );
        void addMovie( const int movieId, const int numCopies );
        void removeSubscriber( const int subscriberId );
        void rentMovie( const int subscriberId, const int movieId );
        void returnMovie( const int subscriberId, const int movieId );
        void showMoviesRentedBy ( const int subscriberId ) const;
        void showSubscribersWhoRentedMovie( const int movieId ) const;
        void showAllMovies();
        void showAllSubscribers();
    private:
        MoviesList movies;
        SubscribersList subscribers;
};
