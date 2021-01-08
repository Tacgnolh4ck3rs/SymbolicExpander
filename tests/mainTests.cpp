#include <gtest/gtest.h>
#include "../solve.hpp"
#include <sstream>
#include <iostream>
#include <cstring>


class MyTest : public ::testing::Test
{
protected:
    static void SetUpTestCase() {
        std::cerr << "TestSuiteSetup" << std::endl;
    }

    static void TearDownTestCase() {

    }
};



//-------------------------------------
//Error code testing
TEST(MyTest, FirstTestCode) {
    ExpSolve thing;
    std::string str("Expand the expression:");
    EXPECT_EQ(str.c_str() ,std::get<0>(thing.select("expand")));
}

TEST(MyTest, SecondTestCode) {
    ExpSolve thing;
    std::string str("Expand the expression:");
    EXPECT_EQ(str.c_str(),std::get<0>(thing.select("Expand")));
}


TEST(MyTest, ThirdTestCode) {
    ExpSolve thing;
    std::string str("Unknown operation code \"");
    EXPECT_EQ(str.c_str(),std::get<0>(thing.select("I have an existential crisis")));
}
//--------------------------------------

//Expand operation testing
//Taking as true WolframAlpha outputs :)


TEST(MyTest, EZPZExp) { //(x+1)*(x+2)*(x+3) --> x**3 + 6*x**2 + 11*x + 6
    ExpSolve thing;
    std::string str("x**3 + 6*x**2 + 11*x + 6");
    EXPECT_EQ(str.c_str(), thing.pyExpand("(x+1)*(x+2)*(x+3)"));
}

TEST(MyTest, KindaComplexAfButWhoReallyKnowsExp) { //(x+1)/(x+2)**2 * (x+3) --> x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)
    ExpSolve thing;
    std::string str("x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)");
    EXPECT_EQ(str.c_str(), thing.pyExpand("(x+1)/(x+2)**2 * (x+3)"));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
