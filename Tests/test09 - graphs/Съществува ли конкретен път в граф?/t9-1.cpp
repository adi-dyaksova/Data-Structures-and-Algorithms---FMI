#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
bool visited[10000];
int graph[1000][1000];
set<int> adj[1000];
int m, n;

int main() {
    cin >> m;
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            adj[i].insert(x);
            adj[x].insert(i);
        }
    }
    int q;
    vector<int> result;
    cin >> q;
    int y,l;
    int last;
    bool flag = false;
    for (int i = 0; i < q; i++)
    {
        cin >> l;
        cin >> last;
        for (int j = 1; j < l; j++)
        {
            cin >> y;
            if (adj[last].find(y) == adj[last].end() && flag ==false) {
                result.push_back(0);
                flag = true;
            }
            last = y;
        }
        if (flag == false)result.push_back(1);
        flag = false;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
