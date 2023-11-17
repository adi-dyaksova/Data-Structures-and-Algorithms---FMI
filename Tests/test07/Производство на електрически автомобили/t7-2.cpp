#include <iostream> 
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == -1) {
            if(!q.empty()) {
                cout << q.top()<< " ";
                q.pop();
            }
        }
        else {
            q.push(temp);
        }
    }
    return 0;
}
