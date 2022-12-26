#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// adding/removing different number of copy on same movie + renting it 

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output18.txt";
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
    MovieRentalSystem MRS( base + "/movies_last.txt", base + "/subscribers_last.txt" );
    cout << endl;

	MRS.addMovie( 42, 2 );
	MRS.rentMovie( 2, 42 );
	MRS.rentMovie( 3, 42 );
	MRS.returnMovie( 3, 42);
	MRS.returnMovie( 2, 42);
	MRS.showSubscribersWhoRentedMovie( 42 );
	cout << endl;
	
	MRS.removeMovie( 42 );
	MRS.addMovie( 42, 1 );
	MRS.rentMovie( 2, 42 );
	MRS.rentMovie( 3, 42 );
	MRS.returnMovie( 3, 42);
	MRS.returnMovie( 2, 42);
	MRS.showSubscribersWhoRentedMovie( 42 );
	cout << endl;
	
	MRS.removeMovie( 42 );
	MRS.addMovie( 42, 3 );
	MRS.rentMovie( 4, 42);
	MRS.rentMovie( 2, 42 );
	MRS.rentMovie( 3, 42 );
	MRS.rentMovie( 5, 42 );
	MRS.returnMovie(4,42);
	MRS.returnMovie(5,42);
	MRS.returnMovie( 3, 42);
	MRS.returnMovie( 2, 42);
	MRS.showSubscribersWhoRentedMovie( 42 );
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}