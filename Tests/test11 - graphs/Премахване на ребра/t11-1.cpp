#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 100;
vector<int> graph[MAX];
bool visited[MAX];
int n, m, result;

int dfs(int start) {
    visited[start] = true;
    int curCompNode = 0;
    for (auto v : graph[start])
    {
        if (!visited[v]) {
            int subtreeNodeCount = dfs(v);
            if (subtreeNodeCount % 2 == 0) {
                result++;
            }
            else {
                curCompNode += subtreeNodeCount;
            }
        }
    }
    return curCompNode + 1;
}


void solve() {
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int v1, v2;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        graph[--v1].push_back(--v2);
        graph[v2].push_back(v1);
    }
    solve();
    return 0;
}
