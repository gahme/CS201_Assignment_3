#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// adding movies alternatingly test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output17.txt";
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
	for( int i = 786; i < 793; i+=2){
		MRS.addMovie( i, 1);
	}
	for( int i = 785; i < 794; i+=2){
		MRS.addMovie( i, 1);
	}
	cout << endl;
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
