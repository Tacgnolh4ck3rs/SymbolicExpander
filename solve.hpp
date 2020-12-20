#include <iostream>
#include <string>

using namespace std;
/**
 * Solve class, wich is used
 * to expand Mathematic expressions!!
 */ 


class Solve{
private:
    string problem;/*! Name of problem */  
    string expression;/*! Mathematic expression to expand */
    string code;/*! Code to identify */  
public:
        Solve(string, string, string);

        /**
         * Function to expand mathematic expressions
         * \param exp the expression to expand
         */ 
        void expandigExpression(string exp);

};
