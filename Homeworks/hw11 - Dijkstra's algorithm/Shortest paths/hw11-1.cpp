#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const long long MAX = 100000;
vector<pair<long long,long long>> graph[MAX];
long long N;
long long dist[MAX];
long long paths[MAX];
bool visited[MAX];

void solve() {    
    for (long long i = 0; i < MAX; i++)
    {
        dist[i]=LONG_LONG_MAX;
        paths[i] = 0;
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({ 0,0});
    dist[0] = 0;
    paths[0] = 1;
//    visited[0] = true;
    while (!pq.empty())
    {
        long long curNode = pq.top().second;
        long long curLength = pq.top().first;
        pq.pop();
        if (!visited[curNode]) {
            visited[curNode] = true;
            for (auto v : graph[curNode])
            {
                long long node = v.first; //node
                long long weight = v.second; //cost
                if (!visited[node] && dist[node] > dist[curNode] + weight) {

                    pq.push({ curLength + weight, node });
                    dist[node] = dist[curNode] + weight;
                    paths[node] = paths[curNode];
                }
                else if (!visited[node] && dist[node] == dist[curNode] + weight) {

                    paths[node] = ((paths[node] % (1000000007)) + paths[curNode] % (1000000007)) % (1000000007);
                }
                 paths[node] %= (1000000007);
            }
        }
        
    }

    if (paths[N - 1] == 0) {
        cout << "-1 0";
    }
    else {
        cout << dist[N - 1] << " " <<(paths[N - 1])%(1000000007);
    }

}

int main() {
    long long M;
    cin >> N >> M;
    long long v1, v2, w;
    for (long long i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> w;
        graph[v1-1].push_back({ v2-1,w });
    }

    solve();
    return 0;
}