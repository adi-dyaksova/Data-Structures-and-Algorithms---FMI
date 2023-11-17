#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<iterator>
#include<set>
using namespace std;
const int MAX = 100000;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
bool nodesFromT[MAX];
int n, m, k, q;
bool flag;

         //weight,vertex
//set < pair<bool,pair<int, int>>> s[MAX];

void dijkstra(int* distance, set<int>& T) {
    //distance[start] = 0;
    //visited[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //pq.push({ 0,start });
    for (auto it = T.begin();it!=T.end();it++)
    {
        pq.push({ 0,*it });
        distance[*it] = 0;
    }
    //for (auto i : graph[start])
    //{
    //    distance[i.first] = i.second;
    //    pq.push({ i.second, i.first });
    //}
    while (!pq.empty())
    {
        pair<int, int> curEl = pq.top();
        pq.pop();
        int curNode = curEl.second;
        if (!visited[curNode]) {
            visited[curNode] = true;
            for (auto it : graph[curNode])
            {
                int v = it.first;
                int weight = it.second;
                if (!visited[v] && (distance[v] > distance[curNode] + weight)) {
                    distance[v] = distance[curNode] + weight;
                    pq.push({ distance[v],v });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //flag = true;
    /*int** d = new int*[MAX];
    for (int i = 0; i < MAX; i++)
    {
        d[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            d[i][j] = (i == j) ? 0 : INT_MAX;            
        }
    }
    cin >> n >> m;
    int v1, v2, weight;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> weight;
        d[v1][v2] = weight;
    }
    bool lastCycle = false;
    for (int k = 0; k < n; ++k) {
        if (k == n - 1)lastCycle = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if (lastCycle) {
                    s[i].insert({ true,{ d[i][j], j }});
                }
            }
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        for (auto it : s[temp])
        {
            it.first = false;
        }
    }
    cin >> q;
    int temp;
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        cout << s[temp].begin()->second.first<<"\n";
    }

    for (int i = 0; i < MAX; i++)
    {
        delete[] d[i];
    }
    delete[] d;
*/

    int distance[MAX];
    for (int i = 0; i < MAX; i++)
    {
        distance[i] = INT_MAX;
    }

    cin >> n >> m;
    int v1, v2, weight;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back({ v2,weight });
        graph[v2].push_back({ v1,weight });
    }
    cin >> k;

    set<int> T;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        T.insert(temp);
    }

    cin >> q;
    int start;
    dijkstra(distance, T);
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        cout << distance[temp]<<"\n";
    }



    //for (int i = 0; i < q; i++)
    //{
    //    cin >> start;
    //    dijkstra(start, distance,T);
    //    //int minDist = INT_MAX;
    //    /*for (auto it = T.begin(); it!=T.end(); it++)
    //    {
    //        if ((distance[*it]) < minDist)minDist = distance[*it];
    //    }
    //    cout << minDist << "\n";*/
    //    if (flag)cout << -1 << "\n";
    //    flag = true;

    //    for (int i = 0; i < MAX; i++)
    //    {
    //        distance[i] = INT_MAX;
    //        visited[i] = false;
    //    }

    //}

    return 0;
}