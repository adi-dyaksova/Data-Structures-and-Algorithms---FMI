#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    int height; //additional
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
        int count = 0;
        root = insert(root, value, count);
    }

    void printSFB() {
      print(root);
    }

private:
  	//you can write helper functions if needed
    Node* root;
    void print(Node* t) { //additional
        if (root == NULL)  return;
        deque<Node*> q;
        deque<Node*> next_level_q;
        q.push_front(root);
        int level = 0;
        while (!q.empty())
        {
           while(!q.empty()){
               Node* cur;
               if(level%2==0){
                   cur = q.front();                
                   cout<< cur->value<<" ";
                   q.pop_front();
                if(cur->left!=NULL)next_level_q.push_back(cur->left); //left
               if(cur->right!=NULL)next_level_q.push_back(cur->right); //right
               }
               else{
                 cur = q.back();
                    cout<< cur->value<<" ";
                   q.pop_back();
           
               if(cur->right!=NULL)next_level_q.push_front(cur->right); //right
               if(cur->left!=NULL)next_level_q.push_front(cur->left); //left
               }    
           }
            q = next_level_q;
            next_level_q.clear();
            level++;
        }
    }
    Node* insert(Node *curNode, int value, int& count) {
        if (curNode == NULL) {
            curNode = new Node(value);
            curNode->height = count;
        } else if (curNode->value < value) {
            count++;
            curNode->right = insert(curNode->right, value,count);
        } else if (curNode->value > value) {
            count++;
            curNode->left = insert(curNode->left, value,count);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
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
  
    tree.printSFB();
    return 0;
}