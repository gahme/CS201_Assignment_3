#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// adding movies after empty movie list test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output16.txt";
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
	MRS.removeMovie( 789 );

	for( int i = 5; i < 10; i++){
		MRS.addMovie( i*10, i );
	}	
	for( int i = 9;i > 4; i--){
		MRS.rentMovie(4, i*10);
	}
	MRS.showAllMovies();

//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}