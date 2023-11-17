#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 10000; 
int n, m;
vector<int> graph[MAX];
bool visited[MAX];
bool cycle;

 void dfs(int start) {
     if (visited[start]) {
         cycle = true;
         return;
     }
     visited[start] = true;
     for (const auto& x : graph[start]) {
         dfs(x);
     }
     visited[start] = false;
 }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string res;
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        cycle = false;
        cin >> n >> m;
        int v1, v2, w;
        for (int i = 0; i < m; i++)
        {
            cin >> v1 >> v2 >> w;
            v1--; v2--;
            graph[v1].push_back({ v2});
        }

        for (int i = 0; i < n; ++i) {
            dfs(i);
        }        
        if (cycle) {
            res.append("1");
        }
        else {
            res.append("0");
        }
        for (int i = 0; i < n; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }
    }
    cout << res;
    return 0;
}