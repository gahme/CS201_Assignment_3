#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------


TEST(movieRentReturn, movieRentReturn1) {
    string inputFile = BASE;
    inputFile += "/output3.txt";
    ifstream file( inputFile );
    string expectedOutput = "";
    string line;
    while ( getline( file, line ) ) {
        expectedOutput = expectedOutput + line + "\n";
    }
    stringstream ss;
    auto buffer = cout.rdbuf( ss.rdbuf() );

//--------------------------------------------------------------------
    string base = BASE;
    MovieRentalSystem MRS( base + "/movies.txt", base + "/subscribers.txt" );
    cout << endl;
    MRS.removeMovie( 600 );
    MRS.removeMovie( 600 );
    MRS.removeMovie( 70 );
    MRS.addMovie( 99, 3 );
    MRS.rentMovie( 1111, 10 );
    MRS.rentMovie( 1111, 20 );
    MRS.rentMovie( 7777, 10 );
    MRS.rentMovie( 6666, 10 );
    MRS.rentMovie( 7777, 80 );
    MRS.rentMovie( 6666, 100 );
    MRS.rentMovie( 4444, 40 );
    MRS.rentMovie( 4444, 50 );
    MRS.rentMovie( 1234, 30 );
    MRS.rentMovie( 1111, 33 );
    MRS.rentMovie( 1234, 33 );
    cout << endl;
    MRS.returnMovie( 7777, 80 );
    MRS.returnMovie( 6666, 100 );
    MRS.returnMovie( 1111, 20 );
    MRS.returnMovie( 4444, 10 );
    MRS.returnMovie( 1111, 20 );
    cout << endl;
    MRS.rentMovie( 3333, 80 );
    MRS.rentMovie( 8888, 100 );
    MRS.rentMovie( 1111, 100 );
    MRS.rentMovie( 1111, 100 );
    cout << endl;
    MRS.rentMovie( 1111, 20 );
    MRS.returnMovie( 1111, 20 );
    MRS.rentMovie( 1111, 20 );
    cout << endl;
    MRS.showMoviesRentedBy( 1111 );
    MRS.showMoviesRentedBy( 8888 );
    MRS.showMoviesRentedBy( 2222 );
    MRS.showMoviesRentedBy( 1234 );
    cout << endl;
    MRS.showSubscribersWhoRentedMovie( 10 );
    MRS.showSubscribersWhoRentedMovie( 100 );
    MRS.showSubscribersWhoRentedMovie( 30 );
    MRS.showSubscribersWhoRentedMovie( 70 );
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
