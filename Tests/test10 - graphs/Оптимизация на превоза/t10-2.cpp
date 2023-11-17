#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n, m, x, y, w;
vector<pair<int, int>> A[100];
vector<int> G[16][100];

bool used[100];

int countA[15000];
int maxLength;

void dfs(int x, int depth, int length) {
    used[x] = true;
    if (depth == 0) {
        countA[length]++;
        if (countA[length] > countA[maxLength] || (countA[length] == countA[maxLength] && maxLength < length)) {
            maxLength = length;
        } 
    }
    else {
        for (auto it : A[x]) {
            int y = it.first;
            if (!used[y]) {
                int w = it.second;
                dfs(y, depth - 1, length + w);
            }
        }
    }
    used[x] = false;
}


int main() {

    cin >> n >> m;



    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        A[--x].push_back({ --y, w });
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        dfs(i, k, 0);
    }

    if (maxLength == 0) cout << -1 << endl;
    else
    cout << maxLength << endl;


    return 0;
}