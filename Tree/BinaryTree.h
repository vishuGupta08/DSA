#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* Left;
    Node* Right;

    Node(int value){
        data = value;
        Left = nullptr;
        Right = nullptr;
    }
};

class BinaryTree
{
public:
    Node* root;
    BinaryTree() { // default constructor
        root = nullptr;
    }

    void insert(int value){
        root = insertRec(root, value);
    }
private:
    Node* insertRec(Node* node, int value){

        if(node == nullptr){
            return new Node(value);
        }
        if(value < node -> data){
          node -> Left =  insertRec(node -> Left, value);
        }
        if(value > node -> data){
          node -> Right =  insertRec(node -> Right, value);
        }
        return node;
    }
};
    
#endif


