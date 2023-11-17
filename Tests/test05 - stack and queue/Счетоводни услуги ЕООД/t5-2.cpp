#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main() {

    stack<int> in;
    int sum = 0;
    stack<int> out;
    int N;
    cin>> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (temp == -1) {
            if (!in.empty()) {
                sum -= in.top();
                out.push(in.top());
                in.pop();        
            }
        }
        else if (temp==-2) {
            if (!out.empty()) {
                in.push(out.top());
                sum += in.top();
                out.pop();
            }

        }
        else if (temp>0) { //else
            in.push(temp);
            sum += temp;
        }
    }

    cout << sum;
    return 0;
}