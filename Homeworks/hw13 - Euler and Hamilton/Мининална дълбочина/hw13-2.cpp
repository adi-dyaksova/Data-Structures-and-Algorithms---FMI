#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int MAX = 1000000;
vector<int> graph[MAX];
int degree[MAX];
int N;
void solve() {
    int size = N;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (degree[i] == 1) {
            q.push(i);
        }
    }
    while (size > 2) {
        int countLeaves = q.size();
        size -= countLeaves;
        for (int i = 0; i<countLeaves;i++)
        {
            int parent = q.front();
            q.pop();
            for (auto child:graph[parent])
            {
                degree[child]--;
                if (degree[child] == 1) {
                    q.push(child);
                }
            }
        }
    }
    set<int> result;
    while (!q.empty()) {
        result.insert(q.front());
        q.pop();
    }
    for (auto node:result)
    {
        cout << node<<" ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int v1, v2;
    for (int i = 0; i < N-1; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        degree[v1]++;
        degree[v2]++;
    }
    solve();
    return 0;
}