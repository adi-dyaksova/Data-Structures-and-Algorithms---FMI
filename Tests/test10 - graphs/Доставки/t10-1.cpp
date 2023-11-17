#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 100000;
        //node, weight
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int dist[MAX];
int N, M;
void dijkstra(int start) {
    for (int i = 0; i < MAX; i++)
    {
        dist[i] = INT_MAX;
    }
                // dist, node
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if (!visited[curNode]) {
            visited[curNode] = true;
            for (auto v: graph[curNode])
            {
                int childNode = v.first;
                int childWeight = v.second;
                if (!visited[childNode] && dist[childNode] > dist[curNode] + childWeight) {
                    dist[childNode] = dist[curNode] + childWeight;
                    pq.push({ dist[childNode], childNode });
                }
            }
        }
    }
    
}

void solve(int start) {
    dijkstra(start);
    for (int i = 0; i < N; i++)
    {
        if (i == start)continue;
        else if (dist[i] == INT_MAX) {
            cout << "-1 ";
        }
        else {
            cout << dist[i] << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int v1, v2, w;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> w;
        graph[v1-1].push_back({ v2-1,w });
        graph[v2-1].push_back({ v1-1,w });
    }
    int start;
    cin >> start;
    solve(start-1);
    return 0;
}