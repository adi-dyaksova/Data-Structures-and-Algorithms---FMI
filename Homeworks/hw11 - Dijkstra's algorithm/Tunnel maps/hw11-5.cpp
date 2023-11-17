#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<algorithm>
#include<climits>
using namespace std;
int MIN, MAX, MID;
int N, M, K;
int Dijkstra(vector<pair<int, pair<int, int>>>Graph[], int s, int d, int n, int weight)
{
    int used[100001];
    vector<int> dist;
    for (int i = 0; i < n + 1; i++)
    {
        used[i] = 0;
        dist.push_back(INT_MAX);
    }
    int node;
    pair<int, pair<int, int>> edge;
    priority_queue <pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
    pq.push({ 0,{s,0} });
    dist[s] = 0;
    while (!pq.empty())
    {

        node = pq.top().second.first;
        pq.pop();
        if (used[node])continue;
        used[node] = 1;
        for (int i = 0; i < Graph[node].size(); i++)
        {
            edge = Graph[node][i];
            if (edge.second.second > weight)continue;
            if (dist[node] + edge.second.first < dist[edge.first])
            {
                dist[edge.first] = dist[node] + edge.second.first;
                pq.push({ dist[edge.first],{edge.first,edge.second.second} });
            }
        }
    }
    return dist[d];
}
void solve(vector<pair<int, pair<int, int>>>* Graph) {
    int result = INT_MAX;
    while (MIN <= MAX)
    {
        MID = MIN + (MAX - MIN) / 2;
        int m = Dijkstra(Graph, 1, N, N, MID);
        if (m > K)
        {
            MIN = MID + 1;
        }
        else
        {
            MAX = MID - 1;
            result = min(result, MID);
        }
    }
    if (result == INT_MAX) {
        cout << -1;
    }
    else {
        cout << result;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    vector<pair<int, pair<int, int>>>* Graph = new vector <pair<int, pair<int, int>>>[N + 1];
    int from, to, weight, lenght;
    MIN = INT_MAX;
    int m = 0;

    for (size_t i = 0; i < M; i++)
    {
        cin >> from >> to >> weight >> lenght;
        Graph[from].push_back({ to,{lenght,weight} });
        if (MIN > weight)MIN = weight;
        if (MAX < weight)MAX = weight;
    }
    solve(Graph);
    
    return 0;
}