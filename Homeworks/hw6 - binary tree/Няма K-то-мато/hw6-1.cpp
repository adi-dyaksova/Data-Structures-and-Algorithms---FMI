#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node() {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int value, Node* left, Node* right) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class BST
{
public:
    BST() {
        this->root = nullptr;
        this->elements = 0;
    }

    void insert(int num) {
        root = insert(root,num);
    }

    void deleteKth(int k) {
        this->root = deleteKthLargest(k);
    }

    void print() {
        inorder(this->root);
    }

private:
    Node* root;
    int elements;

    Node* insert(Node* root, int num) {

        if (root == nullptr) {
            elements++;
            root = new Node(num, nullptr, nullptr);
        }
        else if (num > root->value) {
            root->right = insert(root->right, num);
        }
        else if (num < root->value) {
            root->left = insert(root->left, num);
        }
        return root;
    }

    Node* findKthLargest(Node* node, int k, int& c)
    {
        if (node == NULL)
            return NULL;
        Node* right = findKthLargest(node->right, k, c);
        if (right)return right;
        c++;
        if (c == k)
        {
            return node;
        }
        return findKthLargest(node->left, k, c);
    }

    Node* deleteKthLargest(int K) {
        if (elements < K) return nullptr;
        int count = 0;
        Node* toDelete = findKthLargest(root, K, count);
        /*if (temp->left == nullptr && temp->right == nullptr) {
            delete[] temp;
        }*/

        if (toDelete->left == NULL) {
            Node* temp = toDelete->right;
            delete toDelete;
            return temp;
        }
        else if (toDelete->right == NULL) {
            Node* temp = toDelete->left;
            delete toDelete;
            return temp;
        }

        // If both children exist
        else {

            Node* succParent = toDelete;

            // Find successor
            Node* succ = toDelete->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Delete successor.  Since successor
            // is always left child of its parent
            // we can safely make successor's right
            // right child as left of its parent.
            // If there is no succ, then assign
            // succ->right to succParent->right
            if (succParent != toDelete)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            // Copy Successor Data to root
            toDelete->value = succ->value;

            // Delete Successor and return root
            delete succ;
            return toDelete;
        }
    }

    void inorder(Node* root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout<<this->root->value<<' ';
            inorder(root->right);
        }
    }
};

int findIndKthLargest(vector<int>& vect, int K) {
    int i = 0;
    int ind = 0;
    while (2 * i + 2 < vect.size()) {
        ind = 2 * i + 2;
        i++;
    }
    int count = 1;
    while (count < K) {
        ind = (ind - 1) / 2;
        count++;
        if (count == K)break;

        ind = 2 * ind + 1;
        count++;
        if (count == K)break;

        ind = (ind - 1) / 2;
        ind = (ind - 1) / 2;
        count++;
        //if (count == K)break;
    }

    if (ind < 0 || ind >= vect.size())return -1; //does not have kth element
    return ind;

    //if (2 * ind + 1 < vect.size() || 2 * ind + 2 < vect.size()) { //no left and no right
    //    return (ind - 1) / 2;// not sure
    //}
    //int oldInd = ind;
    //if (2 * oldInd + 2 >= vect.size()) {
    //    return 2 * oldInd + 1;
    //}
}

void RightRootLeft(vector<int>& vect, int i, int& counter, int K, int &index) {
    if (2 * i + 2 < vect.size()) {
        RightRootLeft(vect, 2 * i + 2, counter, K, index);
    }
    counter++;
    if (counter == K) {
        index = i;
    }
    if (2 * i + 1 < vect.size()) {
        RightRootLeft(vect, 2 * i + 1, counter, K, index);
    }
}

//void printWithoutKth(vector<int>& vect, int K) {
//    int ind = findIndKthLargest(vect, K);
//    if (ind != -1) {
//        int i = 0;
//        while () { //TODO
//            if (vect[i] == vect[ind]) {
//
//            }
//        }
//    }
//}

int findMin(vector<int>& vect, int i) {
    if (2 * i + 1 < vect.size()) {
        return findMin(vect, 2 * i + 1);
    }
    else {
        return i;
    }
}

int removeElement(vector<int>& vect, int index) {
    if (2 * index + 2 < vect.size()) {
        int i = findMin(vect, 2 * index + 2);
        vect[index] = vect[i];
        return i;
    } 
    if (2 * index + 1 < vect.size()) {
        return 2 * index + 1;
    } 
    return index;
}

int main() {
    int N , K;
    cin >> N >> K;

    //BST tree;
    vector<int> vect(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        //tree.insert(temp);
        vect[i]=temp;
    }

    int counter = 0, index;
    RightRootLeft(vect, 0, counter, K, index);

    int removeIndex = removeElement(vect, index);

    for (int i = 0; i < vect.size(); i++) {
        if (i != removeIndex) {
            cout << vect[i] << " ";
        }
    }


    return 0;
}