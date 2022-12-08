// Ghulam Ahmed - Section 2 - 22101001

// Sorted link list of transactions for each subscriber in sorted order
class TransactionsList {
    public:
        TransactionsList();
        ~TransactionsList();
        void addTransaction( const int movieId );
        void showTransactions() const;
        void returnMovie( const int movieId );
        bool movieRented( const int movieId ) const;
        int getNumTransactions() const;
    private:
        struct TransactionNode {
            int movieId;
            bool returned;
            TransactionNode *next;
        };
        TransactionNode *head;
        int transactionCount;
};