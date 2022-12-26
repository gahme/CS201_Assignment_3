#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// subscriber alternating renting test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output19.txt";
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
    MovieRentalSystem MRS( base + "/movies_fin.txt", base + "/subscribers_fin.txt" );
    cout << endl;

	for( int i = 1; i < 10 ; i += 2)
		MRS.rentMovie( 1000, i);
	
	for( int i = 2; i < 11 ; i += 2)
		MRS.rentMovie( 1000, i);
		
	for( int i = 1; i < 10 ; i += 2)
		MRS.returnMovie( 1000, i);
		
	cout << endl;
	MRS.showMoviesRentedBy( 1000 );

	
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
