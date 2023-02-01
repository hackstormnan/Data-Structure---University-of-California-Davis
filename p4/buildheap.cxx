#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "json.hpp"
#include "priorityqueue.h"


int main(int argc, char** argv) {

    nlohmann::json jsonObject;
    nlohmann::json resultjson;
    size_t max_size;

    std::ifstream file;
    file.open(argv[1]);
    if (file.is_open()) {
        file >> jsonObject;
    }


    max_size = jsonObject["metadata"]["maxHeapSize"];
    PriorityQueue heap(max_size+300);

    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
    //  std::cout<<"hah"<<std::endl;
        if (itr.key() == "metadata")
            break;

        ////////////////////////////
        for (auto inneritr = jsonObject[itr.key()].begin(); inneritr != jsonObject[itr.key()].end(); ++inneritr) {
          //  std::cout<<"huh"<<std::endl;
            if (inneritr.key() == "key") {
                double insert_key = inneritr.value();
                //std::cout << "insert_key=" << insert_key << std::endl;
                heap.insert(insert_key);
                //std::cout << "insert key" << std::endl;
                break;
            } else if (inneritr.key() == "operation" && inneritr.value() == "removeMin") {
               heap.removeMin();
               break;
                //std::cout << "remove min" << std::endl;
            } else {
                break;
            }
        }/////////////////////////////
    }
    resultjson = heap.JSON();
    resultjson["metadata"]["numOperations"] = jsonObject["metadata"]["numOperations"];
    //output
    std::cout << resultjson.dump(2);
}
