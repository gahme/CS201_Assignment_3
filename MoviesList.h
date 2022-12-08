// Ghulam Ahmed - Section 2 - 22101001

// Sorted link list of movies
class MoviesList {
    public:
        MoviesList();
        ~MoviesList();
        void addMovie( const int movieId, const int numCopies );
        void removeMovie( const int movieId );
        void rentMovie( const int movieId );
        void returnMovie( const int movieId );
        void showAllMovies();
        bool movieExists( const int movieId ) const;
        int getNumCopies( const int movieId ) const;
        int getNumRented( const int movieId ) const;
        int getNumAvailableCopies( const int movieId ) const;
    private:
        struct MovieNode {
            int movieId;
            int numCopies;
            int numRented;
            MovieNode *next;
        };
        MovieNode *head;
};