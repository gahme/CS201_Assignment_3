#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
//Show the list of all subscribers who have rented a particular movie (general)

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output7.txt";
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
    MovieRentalSystem MRS( base + "/movies_mid.txt", base + "/subscribers_mid.txt" );
    cout << endl;
	MRS.rentMovie( 2000, 4321 );
	MRS.rentMovie( 1000, 4321 );
	cout << endl;
	MRS.showSubscribersWhoRentedMovie( 4321 );
	cout << endl; 
	MRS.returnMovie( 1000, 4321 );
	cout << endl;
	MRS.showSubscribersWhoRentedMovie( 4321 );
	cout << endl; 
	MRS.removeSubscriber( 1000 );
	cout << endl; 
	MRS.showSubscribersWhoRentedMovie( 4321 );
	cout << endl;
	MRS.returnMovie( 2000, 4321 );
	MRS.removeSubscriber( 2000 );
	cout << endl;
	MRS.showSubscribersWhoRentedMovie( 4321 );

//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}