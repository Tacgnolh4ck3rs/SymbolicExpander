//Standard headers
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
//Additional headers
#include "solve.hpp"
#include "json.hpp"
#include "argh.h"
#include <string>


using json=nlohmann::json;
using namespace std;

int main(int argc, char **argv) {
    
    expSolve stuff;
    
    argh::parser cmdl;
    cmdl.add_params({"-input", "--fileName"});//Argh! input 
    cmdl.parse(argc,argv);
    string fileName = cmdl({"-input","--fileName"}).str();
    vector<string> arrayValue;
    //Key type is string
    //           value type is vector<string>
    //map< KeyType, ValueType > myMap;
    map< string, vector<string> > myMap;
    ifstream problem(fileName);//ifstream problem("config.json");
    json file=json::parse(problem);//json parsing

    /*
     * The next loop iterates for each member of problems
     */
    for(json& o: file["problems"])
        /*
         * For each problem we insert at myMap the next { key, value }
         * pair: 
         * { key: name of the problem,
         *   value: { expression, code of the operation }
         * }
         * So the value has a 0th component and a 1st component,
         * corresponding to a math expression and to a code of
         * the operation expected (it should be expand by now, the
         * only accepted operation).
         */
        myMap.insert(
                pair<string, vector<string> >(
                    //Key (k.first) would be the name field value
                    o["name"],
                    //Value (k.second) would be the vector containing
                    //fields expr (pos 0) and operation.code (pos 1)
                    {
                        o["expr"],
                        o["operation"]["code"]
                    }
    )
        );
    
    cout << "Symbolic Math Application" << endl << "--------------------------" << endl << endl;
    
    for (auto k : myMap){
        cout << k.first << ". " << get<0>(stuff.select(k.second.at(1)))<<endl;
        if (get<1>(stuff.select(k.second.at(1))))
            break;
        else{
            cout << k.second.at(0) << endl;
            cout << "Result:"<< endl;
            cout << stuff.pyExpand(k.second.at(0)) << endl ;
    }
}
    
    return 0;
}
