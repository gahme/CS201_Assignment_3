#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
//  renting in a loop test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output15.txt";
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
    for( int i = 10; i < 30; i++){
		MRS.addMovie(i,1);
	}

	for( int i = 10; i < 30; i++){
		MRS.rentMovie( 2, i );
	}

	for( int i = 29; i > 9; i--){
		MRS.returnMovie( 2, i );
	}
	MRS.showMoviesRentedBy( 2 );

//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
