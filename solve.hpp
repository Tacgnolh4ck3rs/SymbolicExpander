#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <sstream>
#include <tuple>
//SymbolicC++ headers
#include <pybind11/embed.h>

using namespace std;
namespace py = pybind11;
/**
 * ExpSolve class, wich is used
 * to expand expressions!
 *
 * you could expand Formulas like
 *
 * \f$(x+y+z)^2\f$
 *
 * \f$(x+1)*(x+2)*(x+3)\f$
 *
 * \f$(x+1)/(x+2)**2 * (x+3)\f$
 */


class ExpSolve
{
public:

    ExpSolve() { /*! Class Constructor*/
        py::initialize_interpreter();
        code = py::module::import("expandUtils");
    }

    ~ExpSolve()/*! Class Destructor*/ noexcept(false) {
    }
    /**
     * Function to expand expression using py libraries
     * \param exprStr the function expression
     * \return the function expanded
     */
    string pyExpand(string exprStr)
    {
        //Check that file has been imported
        //py::print(code.attr("__file__")); //debug
        //Reinterpret module as object (Really needed?)
        auto pymodule = py::reinterpret_borrow<py::object>(code);
        //Get function as attr from the object
        auto pyExp = pymodule.attr("expF");
        //Get result of the call as an string
        //std::string aux = pyExp(exprStr).cast<string>(); //less errors, still wont work
        //Untested begin
        std::stringstream aux;
        aux << pyExp(exprStr).cast<string>();

        //untested end
        //DEBUG
        //cout << "Hey, Python said that result is equal to " << aux.str() << endl;
        // SymEngine::print_stack_on_segfault();
        //RCP<const Basic> x= symbol("x");
        return aux.str();
    }
    tuple<string, bool> select(string codeStr)
    {
        string str1="Expand the expression:";
        string strerr="Unknown operation code \"";
        if(codeStr == "Expand" || codeStr == "expand") {
            return std::make_tuple(str1, false);
        } else {
            return std::make_tuple((strerr.append(codeStr)).append("\""),true);
        }
    }
private:
    py::module code;
};
