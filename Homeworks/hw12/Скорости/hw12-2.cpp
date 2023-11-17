#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
const int MAX = 10000;
int n, m;
vector<int> parent;
vector<int>depth;


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b])
            depth[a]++;
    }
}
struct Edge {
    int v1;
    int v2;
    int weight;
    Edge(int v1, int v2, int weight) :v1(v1), v2(v2), weight(weight) {}
    bool operator<(const Edge& other)const {
        return this->weight < other.weight;
    }
};
void solve(vector<Edge>& edges) {
    int min = 0;
    int max = INT_MAX;
    vector<Edge> result;
    parent.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        depth[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int components = n;
    for (size_t j = 0; j < edges.size(); j++)
    {
        for (int i = j; i < edges.size(); i++) {
            if (find_set(edges[i].v1) != find_set(edges[i].v2)) {
                result.push_back(edges[i]);
                union_sets(edges[i].v1, edges[i].v2);
                components--;
            }
            if (components == 1) {
                break;
            }
        }

        if(components == 1) {
          
            int curMin = result.begin()->weight;
            vector<Edge>::iterator iter = result.end();
            iter--;
            int curMax = iter->weight;
            int cur = curMax - curMin;
            int global = max - min;
            if (cur < global) {
                min = curMin;
                max = curMax;
               
            }
             components = n;
             result.clear();
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                    depth[i] = 0;
                }
        }        
    }
    cout << min << " " << max;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Edge>edges;
    cin >> n >> m;
    int v1, v2, w;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        edges.push_back({ v1,v2,w });
    }

    solve(edges);
    return 0;
}
