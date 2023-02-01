

#include <fstream>
#include <string>
#include <iostream>
#include "AVL.h"
#include "json.hpp"


using namespace std;


int main(int argc, char** argv)
{
    BST t;
    
    
    ifstream file;
    file.open(argv[1]);
    //file.open("123.json");
    nlohmann::json jsonObject;
    if (file.is_open()) { file >> jsonObject; }
    // AVL nodes;
    
    
    int n=1;
    int y=-1;
    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
        
       // cout<<"get"<<endl;
        if (itr.key() == "metadata")
            break;
        if(jsonObject[itr.key()]["operation"]=="Insert"){
            
            //cout<<"get"<<endl;
            int key=jsonObject[itr.key()]["key"];
            t.insert(key);
            if(n==1){t.in_root();}
            // nodes.insert(nodes.nodes.root_,3);
        }
        
        
        
        
        n++;
        
        
    }
    
    
    t.is_root();
    t.display();
    t.result["size"]= n-1;
    
    t.print_t();
    //cout<<y<<endl;
    cout<<endl;
    
    
    
    //    t.display();
}
