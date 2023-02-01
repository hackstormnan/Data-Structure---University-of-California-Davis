#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
using namespace std;


int main(int argc, char** argv) {

    std::ifstream file1,file2;
    file1.open(argv[1]);
    file2.open(argv[2]);

    nlohmann::json jsonObject;
    nlohmann::json jsonObject_Almost;

    nlohmann::json outjson;




    if (file1.is_open()) { file1 >> jsonObject; }
    if (file2.is_open()) { file2 >> jsonObject_Almost; }

//std::cout << jsonObject.dump(2) << "\n"    ;

        int size_s = jsonObject["metadata"]["numSamples"];
        int size_a = jsonObject["metadata"]["arraySize"];
        //int num_con=0;
        int counter;
        int num_con=0;
        for(int j=1;j<size_s+1;j++){


          string sample="Sample";
          if(j<10){

          sample= sample+'0';

            }

          sample=sample + to_string(j);

          counter=0;
        for(int i=0;i<size_a;i++){



              if(jsonObject[sample][i]!=jsonObject_Almost[sample][i]){
                outjson[sample][argv[1]]=jsonObject[sample];
                outjson[sample][argv[2]]=jsonObject_Almost[sample];
                     outjson[sample]["Mismatches"][to_string(i)]={jsonObject[sample][i],jsonObject_Almost[sample][i]};
              }

              if(counter==0){num_con++;}
              counter++;


             }
           }

    outjson["metadata"]["File1"]=jsonObject["metadata"];
    outjson["metadata"]["File1"]["name"]=argv[1];
    outjson["metadata"]["File2"]=jsonObject_Almost["metadata"];
    outjson["metadata"]["File2"]["name"]=argv[2];
    outjson["metadata"]["amplesWithConflictingResults"]=num_con;



    std::cout << outjson.dump(2) << "\n"    ;
    //std::cout << jsonObject.dump(2) << "\n"    ;

//most recent
}
