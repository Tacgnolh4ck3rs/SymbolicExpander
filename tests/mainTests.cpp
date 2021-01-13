#include <gtest/gtest.h>
#include "../solve.hpp"
#include <sstream>
#include <iostream>
#include <cstring>

/*
class BaseTest : public ::testing::Test{
};


*/
// Derives a fixture FooTest from BaseTest.
//class FooTest : public BaseTest {
class FooTest : public ::testing::Test {
protected:
    static ExpSolve *thing;
    static void SetUpTestSuite() {
        //SetUp();  // Sets up the base fixture first.
        thing = new ExpSolve();
        std::cout<<"SetUp called :) \n";
    }

    static void TearDownTestSuite() {
        //TearDown();  // Remember to tear down the base fixture
        // after cleaning up FooTest!
        delete thing;
        std::cout<<"TearDown called :(\n";
    }
    virtual ~FooTest() noexcept override {};
};

ExpSolve *FooTest::thing;

//-------------------------------------
//Error code testing
TEST_F(FooTest, FirstTestCode) {
    //ExpSolve thing;
    std::string str("Expand the expression:");
    EXPECT_EQ(str.c_str(),std::get<0>(thing->select("expand")));
}

TEST_F(FooTest, SecondTestCode) {
    //ExpSolve thing;
    std::string str("Expand the expression:");
    EXPECT_EQ(str.c_str(),std::get<0>(thing->select("Expand")));
}


TEST_F(FooTest, ThirdTestCode) {
    //ExpSolve thing;
    std::string str("Unknown operation code \"I have an existential crisis\"");
    EXPECT_EQ(str.c_str(),std::get<0>(thing->select("I have an existential crisis")));
}
//--------------------------------------

//Expand operation testing
//Taking as true WolframAlpha outputs :)


TEST_F(FooTest, EZPZExp) { //(x+1)*(x+2)*(x+3) --> x**3 + 6*x**2 + 11*x + 6
    //ExpSolve thing;
    std::string str("x**3 + 6*x**2 + 11*x + 6");
    EXPECT_EQ(str.c_str(), thing->pyExpand("(x+1)*(x+2)*(x+3)"));
}

TEST_F(FooTest, KindaComplexAfButWhoReallyKnowsExp) { //(x+1)/(x+2)**2 * (x+3) --> x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)
    //ExpSolve thing;
    std::string str("x**2/(x**2 + 4*x + 4) + 4*x/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)");
    EXPECT_EQ(str.c_str(), thing->pyExpand("(x+1)/(x+2)**2 * (x+3)"));
}
