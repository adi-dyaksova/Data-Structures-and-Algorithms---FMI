#include<iostream>
#include<vector>

using namespace std;


int timeIn[1000000];
int timeOut[1000000];
vector<int> g[1000000];
int N, Q;

void dfs(int u, int& cnt)
{
    timeIn[u] = cnt++;
    for (vector<int>::iterator it = g[u].begin(); it != g[u].end(); it++) {
        dfs(*it, cnt);
    }
    timeOut[u] = cnt++;
}

int main()
{
 cin.tie(nullptr);
    cin >> N;

    int x, y;


    int cnt = 0;

    for (int i = 0; i < N-1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }


    dfs(0, cnt);

    cin >> Q;
    int u, v;

    for (int i = 0; i < Q; i++)
    {
       cin >> u >> v;
        if (timeIn[u] < timeIn[v] && timeOut[v] < timeOut[u]) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }

    return 0;
}
