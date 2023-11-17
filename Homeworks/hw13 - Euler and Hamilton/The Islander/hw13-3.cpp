#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
int N, M;
void dfs(int s, unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited) {
    visited[s] = true;
    for (auto cur : graph[s]) {
        if (visited[cur] == false) {
            dfs(cur, graph, visited);
        }
    }
}

bool isConnected(int s, unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited, set<int> nodes) {
    dfs(s, graph, visited);
    for (auto node : nodes)
    {
        if (visited[node] == false)return false;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, v1, v2, firstNode;
    cin >> q;

    for (int i = 0; i < q; i++)
    {

        cin >> N >> M;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        set<int> nodes;
        for (int j = 0; j < M; j++)
        {
            cin >> v1 >> v2;
            if (j == 0)firstNode = v1;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
            visited[v1] = false;
            visited[v2] = false;
            nodes.insert(v1);
            nodes.insert(v2);

        }

        if (nodes.size() == N && isConnected(firstNode, graph, visited, nodes)) {
            int countEvenDegrees = 0;
            int countOddDegrees = 0;
            for (int node : nodes)
            {
                if (graph[node].size() % 2 == 0)countEvenDegrees++;
                else countOddDegrees++;
            }
            if (countEvenDegrees == N) {
                cout << "ecycle\n";
            }
            else if (countOddDegrees == 0 || countOddDegrees == 2) {
                cout << "epath\n";
            }
            else {
                cout << "none\n";
            }

        }
        else {
            cout << "none\n";
        }
    }
    return 0;
}