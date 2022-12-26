#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------


TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output1.txt";
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
    MovieRentalSystem firstMRS( "my_movies.txt", base + "/subscribers.txt" );
    cout << endl;
    MovieRentalSystem MRS( base + "/movies.txt", base + "/subscribers.txt" );
    cout << endl;
    MRS.showAllMovies();
    cout << endl;
    MRS.showAllSubscribers();
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
