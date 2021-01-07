#include <gtest/gtest.h>
#include "../solve.hpp"
#include <sstream>
#include <iostream>
#include <cstring>


class BaseTest : public ::testing::Test{
};

// Derives a fixture FooTest from BaseTest.
class FooTest : public BaseTest {
protected:

    void SetUp() override {
        //SetUp();  // Sets up the base fixture first.
        std::cout<<"SetUp called :) \n";
    }

    void TearDown() override {
        //TearDown();  // Remember to tear down the base fixture
        // after cleaning up FooTest!
        std::cout<<"TearDown called :(\n";
    }

    expSolve thing;
};

//-------------------------------------
//Error code testing
TEST_F(FooTest, FirstTestCode) {
    //expSolve thing;
    std::string str("Expand the expression:");
    EXPECT_EQ(str.c_str(),std::get<0>(thing.select("expand")));
    thing.~expSolve();
}

TEST_F(FooTest, SecondTestCode) {
    //expSolve thing;
    std::string str("Expand the expression:");
    EXPECT_EQ(str.c_str(),std::get<0>(thing.select("Expand")));
}


TEST_F(FooTest, ThirdTestCode) {
    //expSolve thing;
    std::string str("Unknown operation code \"");
    EXPECT_EQ(str.c_str(),std::get<0>(thing.select("I have an existential crisis")));
}
//--------------------------------------

//Expand operation testing
//Taking as true WolframAlpha outputs :)


TEST_F(FooTest, EZPZExp) { //(x+1)*(x+2)*(x+3) --> x**3 + 6*x**2 + 11*x + 6
    //expSolve thing;
    std::string str("x**3 + 6*x**2 + 11*x + 6");
    EXPECT_EQ(str.c_str(), thing.pyExpand("(x+1)*(x+2)*(x+3)"));
}

TEST_F(FooTest, KindaComplexAfButWhoReallyKnowsExp) { //(x+1)/(x+2)**2 * (x+3) --> x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)
    //expSolve thing;
    std::string str("x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)");
    EXPECT_EQ(str.c_str(), thing.pyExpand("(x+1)/(x+2)**2 * (x+3)"));
}
/*
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
