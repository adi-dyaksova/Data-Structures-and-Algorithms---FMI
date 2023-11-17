#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node() {
        value = 0;
        prev = nullptr;
        next = nullptr;
    }

    Node(int v, Node* n, Node* p) {
        value = v;
        next = n;
        prev = p;
    }
};

class doubly_linked_list {
private:
    Node* head;
    Node* tail;

    int _elements;

    Node* goToPos(int pos) {
        if (pos < _elements - pos) {
            int cnt = 0;
            Node* cur = head;
            while (cnt < pos) {
                cur = cur->next;
                cnt++;
            }

            return cur;
        }

        int cnt = _elements - 1;
        Node* cur = tail;
        while (cnt > pos+1) {
            cur = cur->prev;
            cnt--;
        }
        return cur;
    }


    void free(Node* cur, int& count) {
        while (cur != nullptr) {                
            cur->value = -1;
            cur = cur->next;
        }
    }

public:
    doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
        _elements = 0;
    }

    void insert_end(int num) {
        _elements++;

        if (tail == nullptr) {
            head = new Node(num, nullptr, nullptr);
            tail = head;
            return;
        }

        tail->next = new Node(num, nullptr, tail);
        tail = tail->next;
    }

    void insert_begin(int num) {
        _elements++;

        if (head == nullptr) {
            head = new Node(num, nullptr, nullptr);
            tail = head;
            return;
        }

        head = new Node(num, head, nullptr);
    }

    void insert_at(int num, int pos) {
        if (pos < 0 || pos > _elements) {
            throw invalid_argument("Possition out of bounds.");
        }

        if (pos >= _elements) {
            insert_end(num);
            return;
        }

        if (pos == 0) {
            insert_begin(num);
            return;
        }

        _elements++;

        Node* cur = goToPos(pos - 1);
        cur->next = new Node(num, cur->next, cur);
        cur->next->next->prev = cur->next;
    }

    void insert(int num, Node* cur, vector<Node*>& vect) {
        _elements++;
        cur->next = new Node(num, cur->next, cur);
        vect.push_back(cur->next);
        if (cur->next->next){
            cur->next->next->prev = cur->next;
        }
        cur = cur->next;
        
        
        int countAll = 0;
        int count = 1;

        Node* left;
        Node* right;

        do {
            right = cur;
            left = cur;
            while (right->next && right->next->value == cur->value) {
                count++;
                right = right->next;
            }
            while (left->prev && left->prev->value == cur->value) {
                count++;
                left = left->prev;
            }
            if (count >= 3) {
                countAll += count;
                if (left->prev) {
                    left->prev->next = right->next;
                }
                if (right->next) {
                    right->next->prev = left->prev;
                }

                if (!left->prev) head = right->next;
                if (!right->next) tail = left->prev;
                
                if (!left->prev || !right->next) {
                    break;
                }
                if (left->prev->value != right->next->value) break;

                cur = left->prev;
                left->prev = NULL;
                right->next = NULL;
                free(left, count);

            }
            else {
                break;
            }
            count = 1;
        } while (true);
        


        /*while ((left->prev!=NULL || right->next!=NULL) && left->value == right->value){
            while (left != NULL && left->value == cur->value ) {
                left = left->prev;
                count++;
            }
            while (right != NULL && right->value == cur->value) {
                right = right->next;
                count++;
            }


            if (count >= 3) {
                countAll += count;
                if (left==NULL && right==NULL) {
                    cur = head;
                    free(cur, count);
                    break;
                }
                else if (left == NULL && right != NULL) {
                    cur = head;
                    head = right;
                    right->prev->next = nullptr;
                    right->prev = nullptr;
                    free(cur, count);
                    break;
                }
                else if (left != NULL && right == NULL) {
                    tail = left;
                    cur = left->next;
                    tail->next = nullptr;
                    free(cur, count);
                    break;
                }
                else {
                    cur = left->next;
                    left->next = right;
                    right->prev->next = nullptr;
                    right->prev = left;
                    free(cur, count);
                    cur = left;
                }
            }
            else {
                break;
            }
        }*/
        _elements -= countAll;
        cout << countAll << "\n";
    }
     Node* get_tail() {
        return this->tail;
    }

    void erase_begin() {
        if (head == nullptr) {
            return;
        }

        _elements--;

        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void erase_end() {
        if (tail == nullptr) {
            return;
        }

        _elements--;

        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    void erase_at(int pos) {
        if (pos < 0 || pos >= _elements) {
            throw invalid_argument("Possition out of bounds.");
        }

        if (pos == 0) {
            erase_begin();
            return;
        }

        if (pos == _elements - 1) {
            erase_end();
            return;
        }

        _elements--;

        Node* cur = goToPos(pos - 1);

        Node* temp = cur->next;
        cur->next = temp->next;
        cur->next->prev = cur;
        delete temp;
    }

    void reverse() {
        if (_elements == 2) {
            swap(head->value, head->next->value);
            return;
        }

        Node* forward = head;
        Node* backward = tail;

        int cnt = 0;
        while (cnt < _elements / 2) {
            swap(forward->value, backward->value);
            forward = forward->next;
            backward = backward->prev;
            cnt++;
        }
    }

    int get_begin() {
        return head->value;
    }

    int get_end() {
        return tail->value;
    }

    int get(int pos) {
        if (pos >= _elements || pos < 0) {
            throw invalid_argument("Possition out of bounds.");
        }

        return goToPos(pos)->value;
    }

    int elements() {
        return _elements;
    }

    string to_string() {
        string res = "[";

        Node* cur = head;
        while (cur != nullptr) {
            res.append(std::to_string(cur->value));
            if (cur->next != nullptr) {
                res.append(", ");
            }

            cur = cur->next;
        }

        res.append("]");
        return res;
    }

    void print() {
        if (_elements == 0) {
            cout << -1 << "\n";
        }
        else {
            Node* curr = head;
            while (curr != NULL) {
                cout << curr->value << ' ';
                curr = curr->next;
            }
        }
        
    }

    void free_list() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        Node* cur = head->next;

        while (cur != nullptr) {
            delete temp;

            temp = cur;
            cur = cur->next;
        }

        delete temp;
        _elements = 0;
    }
};

int main() {
    int N, Q;
    std::cin >> N;
    doubly_linked_list balls;
    vector<Node*> vect(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin >> temp;
        balls.insert_end(temp);
        vect[i] = balls.get_tail();
    }
    std::cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int pos, col;
        std::cin >> pos >> col;
        if (balls.elements() == 0) {
            cout << "Game Over\n";
        }
        else {
            while (vect[pos]->value == -1) pos--;
            balls.insert(col, vect[pos],vect);

        }
        
    }
    balls.print();
    cout << '\n';
    

    
    return 0;
}