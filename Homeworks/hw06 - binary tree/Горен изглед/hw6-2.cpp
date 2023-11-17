#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 2000000;
const int MAX_DEPTH = 1000000;
vector<pair<int, int>> valAnDepth(MAX);

void rootLeftRight(vector<pair<int,int>>& V, int i, int pos, int depth) {
    if (valAnDepth[pos].first < 0 || valAnDepth[pos].second > depth) { 

        valAnDepth[pos] = { i, depth };
    }

    if (V[i].first != -1) {
        rootLeftRight(V, V[i].first, pos - 1,depth+1);
    }
    if (V[i].second != -1) {
        rootLeftRight(V, V[i].second, pos + 1,depth+1);
    }
}

int main() {
    
    
    for (int i = 0; i < MAX; i++)
    {
        valAnDepth[i].first = -1;
        valAnDepth[i].second = MAX_DEPTH;
    }

    int N;
    cin >> N;
    vector<pair<int, int>> V(N);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        V[i] = { x,y };
    }
    

    rootLeftRight(V,0, MAX/2,0);

    for (int i = 0; i < MAX; i++) {
        if (valAnDepth[i].first != -1) cout << valAnDepth[i].first << " ";
    }
    return 0;
}