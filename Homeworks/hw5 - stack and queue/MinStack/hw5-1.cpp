#include<iostream>
#include<string>
#include<climits>
#include<stack>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
    Node() {
        this->value = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int value, Node* prev,Node* next) {
        this->value = value;
        this->prev = prev;
        this->next = next;    
    }
};

class Stack {
private:
    Node* head;
    Node* tail;
    int elements;
   
public:
    Stack() {
        head = nullptr;
        tail = nullptr;
        
        elements = 0;
    
    }
    void push(int value) {
        elements++;
        
        if (tail == nullptr) {
            head = new Node(value, nullptr,nullptr);
            tail = head;
        }
        else {
            tail->next = new Node(value, tail, nullptr);
            tail = tail->next;
        }
    }

    int peek() {
        return this->tail->value;
    }
   
    void pop() {
        if (elements == 0) {
            cout << "list is empty\n";
        }
        else {    
            elements--;
            Node* temp = tail;
            tail = tail->prev;
            if (tail == nullptr) {
                head = tail;
            }
            else {
                tail->next = nullptr;
            }
            delete[] temp;    
        }
    }
    int getElements() {
        return elements;
    }
};

int main() {
    
    Stack main;
    Stack minEl;
    int N;
    cin >> N;
    string str;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        if (str == "push") {
            int num;
            cin >> num;
            main.push(num);
            if (minEl.getElements()==0 || minEl.peek() > num) {
                minEl.push(num);
            }
        }
        else if (str == "pop") {
            if (main.peek() == minEl.peek()) {
                minEl.pop();
            }
            main.pop();
        }
        else if (str == "peek") {
            cout<<main.peek()<<'\n';
        }
        else if (str == "min") {
            cout << minEl.peek()<<'\n';
        }
    }
    return 0;
}