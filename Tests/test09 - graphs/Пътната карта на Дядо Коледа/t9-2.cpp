#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
bool visited[100000];
vector<int> graph[100000];
int m, n;
void bfs(int start) { //find path from start to end
    queue<int> q;
    visited[start] = true;
    q.push(start);
    int level = 0; //1
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < graph[temp].size(); i++)
        {
            if (!visited[graph[temp][i]]) {
                visited[graph[temp][i]] = true;
                q.push(graph[temp][i]);
            }
        }
    }
}

int dfsUtil(int start) {
    visited[start] = true;
    stack<int> st;
    int counter = 0;
    st.push(start);
    while (!st.empty()) {
        int x = st.top();
        visited[x] = true;
        st.pop();
        counter++;
        for (int i = 0; i < graph[x].size(); i++)
        {
            if (!visited[graph[x][i]]) {
                st.push(graph[x][i]);
            }
        }
    }
    return counter;
    
}

int dfs() {
    int components = 0;
    for (int i = 0; i < m; i++)
    {
        if (!visited[i]) {
            int c = dfsUtil(i);
            if (c > 1) {
                components++;
            }        
        }
    }
    return components;
}

int main() {

    cin >> m >> n;
    int v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << dfs();
    return 0;
}