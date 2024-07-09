#include "BinaryTree.h"
#include <iostream>
using namespace std;

void preOrderRec(Node* node){
    if(node != nullptr){
        cout << node -> data <<" ";
        preOrderRec(node -> Left);
        preOrderRec(node-> Right);
    }

}

void inOrderRec(Node* node){
    if(node != nullptr){
        inOrderRec(node -> Left);
        cout<< node -> data << " ";
        inOrderRec(node -> Right);
    }
}

void postOrderRec(Node* node){
    if(node != nullptr){
        postOrderRec(node -> Left);
        postOrderRec(node -> Right);
        cout<<node -> data<< " ";
    }
}
int main(){
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);

    // preOrderRec(tree.root);
    // inOrderRec(tree.root);
    postOrderRec(tree.root);

}