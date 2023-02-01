#include <iostream>
#include <fstream>
#include "json.hpp"
#include <iomanip>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {


    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    nlohmann::json outjson;
    if (file.is_open()) { file >> jsonObject; }



    int size_s = jsonObject["metadata"]["numSamples"];
    int size_a = jsonObject["metadata"]["arraySize"];
    //cout<<size_s<<endl<<size_a;
    int num_con = 1;
    for(int j = 1;j < size_s + 1; j++){


      string sample="Sample";


      if(j<10){

      sample= sample+'0';

        }

      sample=sample + to_string(j);


    for(int i=0;i<size_a-1;i++){

        if(jsonObject[sample][i]>jsonObject[sample][i+1]){
          //  int g=j;
            outjson[sample]["ConsecutiveInversions"][to_string(i)]={jsonObject[sample][i],jsonObject[sample][i+1]};
            outjson[sample]["sample"] = jsonObject[sample];

          }
          if(i==j-2) {num_con++;}


         }
       }

    outjson["metadata"]=jsonObject["metadata"];
    outjson["metadata"]["file"]=argv[1];
    //not sure
    outjson["metadata"]["numSamples"]=size_s;
    outjson["metadata"]["sampleWithInversions"]=num_con;




  std::cout << outjson.dump(2) << "\n"    ;



}
