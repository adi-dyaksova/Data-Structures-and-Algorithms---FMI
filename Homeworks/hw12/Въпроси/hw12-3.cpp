#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 100000;
int parent[MAX];
int n, m;

void setParent(int v1, int v2) {
    int oldParent = parent[v1];
    int newParent = parent[v2];
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == oldParent) {
            parent[i] = newParent;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string ans;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int v1, v2;

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        v1--;
        v2--;
        if (parent[v1] != parent[v2]) {
            setParent(v1, v2);
        }
        
    }
    int q;
    cin >> q;
    int command;
    for (int i = 0; i < q; i++)
    {
        cin >> command >>v1>>v2;
        v1--; v2--;
        if (command == 1) {
            if (parent[v1] == parent[v2]) {
                ans.append("1");
            }
            else {
                ans.append("0");
            }
        }
        if (command == 2) {
            if (parent[v1] != parent[v2]) {
                setParent(v1, v2);
            }
        }
    }
    cout << ans;
    return 0;
}