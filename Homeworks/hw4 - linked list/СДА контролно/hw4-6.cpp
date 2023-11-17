#include<vector>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node() {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int value, Node* next, Node* prev) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

class linked_list {
private:
    Node* head;
    Node* tail;
    Node* mid;

    int countElements;

    Node* goToPos(int pos) {
        int counter = 0;
        Node* cur = head;
        while (counter < pos) {
            cur = cur->next;
            counter++;
        }
        return cur;
    }

public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
        mid = nullptr;
        countElements = 0;
    }

    int get_elements() {
        return countElements;
    }

    void insert_end(int num) {
        countElements++;

        if (tail == nullptr) {
            head = new Node(num, nullptr, nullptr);
            tail = head;
            mid = head;
            return;
        }

        tail->next = new Node(num, nullptr, tail);
        tail = tail->next;
        if (countElements % 2 == 0 && countElements != 2) {
            mid = mid->next;
        }
    }
   
    void erase_end() {
        countElements--;
        if (countElements == 0) {
            head = nullptr;
            tail = nullptr;
            mid = nullptr;
        }
        else {
            
            Node* temp = this->tail;
            this->tail = this->tail->prev ;
            this->tail->next = nullptr;
            delete temp;
           
            if (countElements % 2 != 0 && countElements != 1) {
                mid = mid->prev;
            }
        }    
    }

    void print_data() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }

    void disarrange() { 
      
        if (this->countElements > 1) {
            if (countElements == 2) {
                swap(head->value, head->next->value);
            }
            else {
                Node* temp = tail;
                tail->next = head;
                head->prev = tail;
                
                head = mid->next;
                head->prev = nullptr;

                tail = mid;
                tail->next = nullptr;

                mid = temp;
                if (countElements % 2 != 0) {
                    mid = mid->prev;
                }
            }
        }
    }

    ~linked_list() {
        if (head == nullptr) {
            return;
        }

        Node* prev = head;
        Node* cur = head->next;

        while (cur != nullptr) {
            delete prev;

            prev = cur;
            cur = cur->next;
        }

        delete prev;
        countElements = 0;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    linked_list list;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string command;
        cin>>command;
        if (command == "gun") {
            list.erase_end();
        }
        else if (command == "milen") {
            list.disarrange();
        }
        else {
            int theme;
            cin >> theme;
            list.insert_end(theme);
        }
    }

    cout << list.get_elements() << '\n';
    list.print_data();
    

    return 0;
}
