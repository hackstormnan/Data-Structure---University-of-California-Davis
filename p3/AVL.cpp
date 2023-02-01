
#include <fstream>
#include <string>

#include "AVL.h"
#include "json.hpp"

#include<iostream>

using namespace std;

/*
struct BST::node
{
    int data;
    node* left;
    BST::node* right;
    BST::node* parent;
    int height;
    int state;
};*/
    
    
    
BST::node* BST::insert(int x, BST::node* t)
    {
        if(t == NULL)
        {
            t = new BST::node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
            
        }
        else if(x < t->data)
        {
            BST::node *lchild=insert(x, t->left);
            t->left=lchild;
            lchild->parent = t;
            
            
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            BST::node *rchild=insert(x, t->right);
            t->right=rchild;
            rchild->parent = t;
            
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }
        
        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }
    
    BST::node* BST::singleRightRotate(BST::node* &t)
    {
       // cout<<"singleright"<<endl;
        BST::node* u = t->left;
        t->left = u->right;
        u->right = t;
        // cout<<"this undergoes right rota!"<<endl;
        
        t->height = max(height(t->left), height(t->right))+1;
        
        t->parent=u;
        
        u->height = max(height(u->left), t->height)+1;
        
        
        return u;
    }
    
    BST::node* BST::singleLeftRotate(BST::node* &t)
    {
       // cout<<"singleleft"<<endl;
        //cout<<"this undergoes right rota!"<<endl;
        BST::node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        
        t->parent=u;
        
        return u;
    }
    
    BST::node* BST::doubleLeftRotate(BST::node* &t)
    {
           // cout<<"doiubleleft"<<endl;

        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    
    BST::node* BST::doubleRightRotate(BST::node* &t)
    {
        //cout<<"really?";
        cout<<"doiublerightt"<<endl;

        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
    
    int BST::height(BST::node* t)
    {
        return (t == NULL ? -1 : t->height);
    }
    
    int BST::getBalance(BST::node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }
    
    
    int BST::bfactor(BST::node* p)
    {
        return height(p->right)-height(p->left);
    }
    
    void BST::inorder(BST::node* t)
    {
//        int n=0;
        //nlohmann::json result;
        if(t == NULL)
            return;
        inorder(t->left);
        
        
        result[to_string(t->data)]["balance factor"] = bfactor(t);
        result[to_string(t->data)]["height"]=t->height;
        if(t->left){
            result[to_string(t->data)]["left"]=t->left->data;
        }
        if(t->right){
            result[to_string(t->data)]["right"]=t->right->data;
        }
        if(t->state==-1){
            result[to_string(t->data)]["root"]= true;
            result["height"]=t->height;
            result["root"]=t->data;
        }else {
            result[to_string(t->data)]["parent"]=t->parent->data;
        }
        
        /*cout << "data is"<<t->data<<endl;;
         cout << "bf is"<<bfactor(t)<<endl;
         cout << "high is"<<t->height<<endl;
         cout << "pa is"<<t->parent->data<<endl;
         if(t->right){
         cout << "rg is"<<t->right->data<<endl;}
         if(t->left){
         cout<<"lf is"<<t->left->data<<endl;
         }
         if(t->state==-1){cout<<"is a leaf"<<endl;}
         
         cout<<"\n\n";*/
        
        
        inorder(t->right);
    }
    
    
    
    BST::BST()
    {
        root = NULL;
    }
    
    
    void BST::in_root(){
        root->height=max(height(root->left), height(root->right))+1;
        
    }
    void BST::insert(int x)
    {
        root = insert(x, root);
    }
    
    
    void BST::display()
    {
        inorder(root);
        //cout << endl;
    }
    void BST::is_root(){
        root->state=-1;
        
        
        
    }
    void BST::print_t(){
        std::cout << result.dump(2) << "\n"    ;
    }



