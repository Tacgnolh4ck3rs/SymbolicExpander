#include <string>
#include <iostream>
#include "json.hpp"
#include <fstream>

using json=nlohmann::json;
using namespace std;

int main(int argc, char **argv) {
    json Din;
    ifstream user("user.json");
    user>>Din;
    string functionStr=Din["function"];
    double rangeMin=Din["range"]["min"];
    double rangeMax=Din["range"]["max"];
    int partitions=Din["partitions"];
    cout<<"Function: ("<<functionStr<<"), Range: ["<<
        rangeMin<<" - "<< rangeMax<<"]. Partitions: "<<
        partitions<<endl;


    return 0;
}
