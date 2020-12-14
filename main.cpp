#include <string>
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <vector>
using json=nlohmann::json;
using namespace std;

int main(int argc, char **argv) {
    
    vector<string> arrayValue;
    ifstream problem("config.json");
    json file=json::parse(problem);
    
    for(json& o: file["problems"]){
    json& gi=o;
    arrayValue.push_back(gi["name"]);
    cout<<"name: "<<gi["name"]<<endl;
    arrayValue.push_back(gi["expr"]);
    cout<<"expresion: "<<gi["expr"]<<endl;
    arrayValue.push_back(gi["operation"]["code"]);
    cout<<"code: "<<gi["operation"]["code"]<<endl;
    }
    //for(int pos=0; arrayValue.size();pos++)
    //cout<<arrayValue.at(pos)<<endl;
    
    return 0;
}
