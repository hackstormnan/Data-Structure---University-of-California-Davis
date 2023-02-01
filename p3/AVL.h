#include <memory>
#include <string>
#include <iostream>
//#include "BST.h"
#include "json.hpp"


class BST {
public:
    struct node
    {
        int data;
        node* left;
        node* right;
        node* parent;
        int height;
        int state;
    };
    
    node* root;
    nlohmann::json result;

    node* insert(int x, node* t);
    
    
    node* singleRightRotate(node* &t);
   
    
    node* singleLeftRotate(node* &t);
    
    node* doubleLeftRotate(node* &t);
   
    
    node* doubleRightRotate(node* &t);
   
    
    int height(node* t);
    
    
    int getBalance(node* t);
   
    
    
    int bfactor(node* p);
    
    
    void inorder(node* t);
   
    
    BST();
    
    
    
    void in_root();
    void insert(int x);
    
    
    void display();
  
    void is_root();
    void print_t();
    
    
   
 
}; // class BST
