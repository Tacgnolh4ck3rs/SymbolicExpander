#include "argh.h"
#include "json.hpp"
#include "solve.hpp"
#include <fstream>

using json=nlohmann::json;

int main(int argc, char **argv) {

    expSolve stuff;

    argh::parser cmdl;
    cmdl.add_params({"-f", "--file"});
    cmdl.parse(argc,argv);

    if(!(cmdl({"-f","--file"}))) {
        std::cerr << "A file argument must be provided :(\n";
        return 1;
    }

    std::string file = cmdl({"-f","--file"}).str();
    //Key type is string
    //value type is vector<string>
    //map< KeyType, ValueType > myMap;
    std::map< std::string, std::vector<std::string> > myMap;
    std::ifstream ii(file);
    json data=json::parse(ii);//json parsing

    /*
     * The next loop iterates for each member of problems
     */
    for(json& o: data["problems"]) {
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
            pair<std::string, std::vector<std::string> >(
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
    }

    std::cout << std::endl <<"Symbolic Math Application" << endl << "--------------------------" << endl << endl;

    for (auto k : myMap) {
        std::cout << k.first << ". " << std::get<0>(stuff.select(k.second.at(1)))<<std::endl;
        if (std::get<1>(stuff.select(k.second.at(1)))){
            break;
        }
        std::cout << k.second.at(0) << std::endl;
        std::cout << "Result:"<< endl;
        std::cout << stuff.pyExpand(k.second.at(0)) << std::endl<<std::endl;
    }
    return 0;
}
