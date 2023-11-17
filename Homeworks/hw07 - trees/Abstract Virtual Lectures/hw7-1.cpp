#include<iostream> 
using namespace std;

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int max(int a, int b);

int height(Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return node;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    return x;
}
 
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left),
        height(x->right)) + 1;
    y->height = max(height(y->left),
        height(y->right)) + 1;
 
    return y;
}

int getBalance(Node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{

    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    node->height = 1 + max(height(node->left),
        height(node->right));
    int balance = getBalance(node);

    // Left Left Case  
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case  
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case  
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case  
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* findMin(Node* t) //most left
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

Node* remove(int x, Node* root) {
    //Deletion
    Node* temp;
    if (root == NULL)
        return NULL;
    else if (x < root->key)
        root->left = remove(x, root->left);
    else if (x > root->key)
        root->right = remove(x, root->right);
    else {
        Node* temp;
        //2 childs
        if (root->left && root->right) {
            temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(temp->key, root->right);
        }
        else {
            temp = root;
            if (root->left == NULL) {
                root = root->right;
            }
            else if (root->right == NULL) {
                root = root->left;
            }
            delete[] temp;
        }
    }

    if (root == NULL)
        return root;

    // Balance tree 
    root->height = 1 + max(height(root->left),
        height(root->right));

    int balance = getBalance(root);

    // Left Left Case  
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case  
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case  
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case  
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printInorder(Node* t) {
    if (t == NULL)
        return;
    printInorder(t->left);
    cout << t->key << " ";
    printInorder(t->right);
}


int main() {
    Node* root=NULL;
    int N;
    cin >> N;
    string command;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        if (command == "add") {
            int num;
            cin >> num;
            root = insert(root,num);
        }
        else if (command == "del") {
            int num;
            cin >> num;
         root = remove(num,root);
        }
        else if (command == "inorder") {
            printInorder(root);
            cout << '\n';
        }
    }

    return 0 ;
}