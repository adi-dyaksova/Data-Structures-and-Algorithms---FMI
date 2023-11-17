#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

  void deletePenultimateAndPrint() {
       deleteHelperFunc(root);
      printInorder(root);

    }

private:
  	//you can write helper functions if needed
    Node* root;
    void deleteHelperFunc(Node* node){
        if(node==NULL)return;
        if(node->left!=NULL){
            if(node->left->left==NULL && node->left->right==NULL){
                if(node->right==NULL){
                    node->value = node->left->value;
                    node->left=NULL;
                }
                else if(node->right->left==NULL && node->right->right==NULL){
                    node->value = node->right->value;
                    node->right = NULL;
                }
            }
        }
        else if(node->right!=NULL){
            if(node->right->left==NULL && node->right->right==NULL){
                node->value = node->right->value;
                node->right= NULL;
            }
        }
        if(node->right != NULL && (node->right->left!= NULL || node->right->right!=NULL)){
            deleteHelperFunc(node->right);
        }
        if(node->left != NULL && (node->left->left!= NULL || node->left->right!=NULL)){
            deleteHelperFunc(node->left);
        }
    }
    
    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
           void printInorder(Node* t) { //left root right
        if (t == NULL)
            return;
      /* if(t->left!=NULL)*/ printInorder(t->left);
        cout << t->value << " ";
    /* if(t->right!=NULL)*/ printInorder(t->right);
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.deletePenultimateAndPrint();
    return 0;
}