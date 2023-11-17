#include<string>
#include <iostream>
#include <assert.h> 
using namespace std;

struct Node {
    int value;
    Node* next;

    Node() {
        value = 0;
        next = nullptr;
    }

    Node(int v, Node* l) {
        value = v;
        next = l;
    }
};

class linked_list {
private:
    Node* head;
    Node* tail;

    int countElements;

    /*Node* goToPos(int pos) {
        int cnt = 0;
        Node* cur = head;
        while (cnt < pos) {
            cur = cur->next;
            cnt++;
        }
        return cur;
    }*/

public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
        countElements = 0;
    }

    void insert_end(int num) {
        countElements++;

        if (tail == nullptr) {
            head = new Node(num, nullptr);
            tail = head;
            return;
        }

        tail->next = new Node(num, nullptr);
        tail = tail->next;
    }
   
    void reverse() {
        if (countElements == 2) {
            swap(head->value, head->next->value);
            return;
        }

        Node* prev = head;
        Node* cur = head->next;
        Node* next = cur->next;

        while (next != nullptr) {
            cur->next = prev;

            prev = cur;
            cur = next;
            next = next->next;
        }

        cur->next = prev;
        head->next = nullptr;
        swap(head, tail);
    }

    void change2(int X, int Y) {
      
        Node* dummy = new Node;
        Node* lastY = dummy;
        int count = 0;
        bool flag = true;
        Node* curr;
        Node* last = dummy;
        curr = this->head;

        while (curr) {
            count++;
            Node* next = curr->next;
            if (flag) {
                curr->next = lastY->next;
                lastY->next = curr;
                if (count == 1) {
                    last = curr;
                }
                if (count == X) {
                    count = 0;
                    flag = false;
                }
            }
            else {
                last->next = curr;
                curr->next = nullptr;
                last = curr;
                if (count == Y) {
                    count = 0;
                    flag = true;
                    lastY = last;
                }
            }

            curr = next;
        }
        this->head = dummy->next;
        this->tail = last;
        delete dummy;
    }

    
    

    void free() {
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


    void print() {
        Node* curr = this->head;
        while (curr) {
            cout << curr->value << '\n';
            curr = curr->next;
        }
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X, Y;
    cin >> N >> X >> Y;
    linked_list list;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        list.insert_end(temp);
    }

    list.change2(X, Y);
    list.print();

    //free

    return 0;
}