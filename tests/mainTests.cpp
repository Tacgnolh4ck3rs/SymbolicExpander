#include <gtest/gtest.h>
#include "../solve.hpp"

//-------------------------------------
//Error code testing
TEST(CodeTest, FirstTestCode) {
    expSolve thing;
    ASSERT_EQ("Expand the expression:",std::get<0>(thing.select("expand")));
}

TEST(CodeTest, SecondTestCode) {
    expSolve thing;
    ASSERT_EQ("Expand the expression:",std::get<0>(thing.select("Expand")));
}


TEST(CodeTest, ThirdTestCode) {
    expSolve thing;
    ASSERT_EQ("Unknown operation code \"",std::get<0>(thing.select("I have an existential crisis")));
}
//--------------------------------------

//Expand operation testing
//Taking as true WolframAlpha outputs :)


TEST(ExpTest, EZPZExp) { //(x+1)*(x+2)*(x+3) --> x**3 + 6*x**2 + 11*x + 6
    expSolve thing;
    ASSERT_EQ("x**3 + 6*x**2 + 11*x + 6", thing.pyExpand("(x+1)*(x+2)*(x+3)"));
}

TEST(ExpTest, KindaComplexAfButWhoReallyKnowsExp) { //(x+1)/(x+2)**2 * (x+3) --> x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)
    expSolve thing;
    ASSERT_EQ("x**2/(x**2 + 4*x + 4) + (4*x)/(x**2 + 4*x + 4) + 3/(x**2 + 4*x + 4)", thing.pyExpand("(x+1)/(x+2)**2 * (x+3)"));
}



