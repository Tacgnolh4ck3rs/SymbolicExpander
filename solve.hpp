#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <tuple>
//SymbolicC++ headers
#include <pybind11/embed.h>

using namespace std;
namespace py = pybind11;

class expSolve
{
public:
    expSolve() {
        //Import the developed python 3 file with functions
        code = py::module::import("expandUtils");
    }
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
        string strerr="Unknown operation code ";
        if(codeStr == "Expand" || codeStr == "expand") {
            return std::make_tuple(str1, false);
        } else {
            return {(strerr.append(codeStr)).append("\""),true};
        }
    }
    py::module code;
    py::scoped_interpreter guard{};
};
