#include<iostream>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;

void printDeq(deque<int>& deq) {
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << ' ';
    }
}


int main() {
    int N;
    cin >> N;
    deque<int> positive;
    deque<int> negative;

    for (size_t i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        if (temp > 0) {
            positive.push_back(temp);
        }
        else if (temp < 0) {
            if (positive.empty()) {
                negative.push_back(temp);
                continue;
            }
            while (!positive.empty() && abs(temp) > positive.back()) {
                positive.pop_back();
            }
            if (positive.empty()) {
                negative.push_back(temp);
            }
            else {
                if (abs(temp) == positive.back()) {
                    positive.pop_back();
                }
            }
        }
        else { //abs(temp)==positive.back()
            if (positive.empty()) {
                negative.push_back(temp);
            }
            else {
                positive.pop_back();
            }    
        }

    }
    printDeq(negative);
    printDeq(positive);
    return 0;
}