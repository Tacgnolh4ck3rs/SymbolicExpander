//Standard headers
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
//Additional headers
#include "json.hpp"
#include "argh.h"
//#include "symboliccpp/symbolicc++.h"
//SymbolicC++ headers

using json=nlohmann::json;
using namespace std;

int main(int argc, char **argv) {
    //SymEngine::print_stack_on_segfault();
    //RCP<const Basic> x= symbol("x");
    argh::parser cmdl;
    cmdl.add_params({"-input", "--fileName"});//Argh! input 
    cmdl.parse(argc,argv);
    string fileName = cmdl({"-input","--fileNme"}).str();
    vector<string> arrayValue;
    //Key type is string
    //           value type is vector<string>
    //map< KeyType, ValueType > myMap;
    map< string, vector<string> > myMap;
    ifstream problem(fileName);//ifstream problem("config.json");
    json file=json::parse(problem);//json parsing

    for(json& o: file["problems"])
        myMap.insert(pair<string, vector<string> >(o["name"], {
        o["expr"],
        o["operation"]["code"]
    }));
    for (auto k : myMap)
        cout <<
             "Problem name: " << k.first << endl <<
             "Expression: " << k.second.at(0) << endl <<
             "Operation code: " << k.second.at(1) << endl;
    return 0;
}
