#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[10000]; //1000
int color[10000]; //1000


bool dfsCycle(int start) {
    color[start] = 1;
    for (int i:adj[start])
    {
        if (color[i] == 1)return true;
        if (color[i] == 0 && dfsCycle(i)==true) {
            return true;
        }
    }
    color[start] = 2;
    return false;
}
bool hasCycle(int v) {
    for (int i = 0; i < v; i++)
    {
        if (color[i] == 0) {
            if (dfsCycle(i)==true){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {

        for (int i = 0; i < 10000; i++)
        {
            adj[i].clear();
            color[i] = 0;
        }
       
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            adj[v1-1].push_back(v2-1); 
        }
        if (hasCycle(v)) {
            cout << "true ";
        }
        else {
            cout << "false ";
        }
    }
    return 0;
}