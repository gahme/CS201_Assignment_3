#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// increasing adding, decreasing removing movie test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output14.txt";
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
	for( int i = 2; i <= 100; i++){
		MRS.addMovie( i , 2 );
	}
	MRS.showAllMovies();
	for( int i = 100; i > 2; i--){
		MRS.removeMovie( i );
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
