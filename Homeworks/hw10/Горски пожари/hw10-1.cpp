#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int arr[4000][4000];
bool used[4000][4000];

int solve(int N, int x, int y) {
    used[x][y] = true;
    int minX = x, maxX = x;
    int minY = y, maxY = y;
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty()) {    
        auto a = q.front();
        q.pop();
        int i = a.first, j = a.second;
        if (i > 0 && arr[i-1][j] && !used[i - 1][j]) {
            if (i - 1 < minX) minX = i - 1;
            used[i - 1][j] = true;
            q.push({ i - 1, j });
        }
        if (i < N-1 && arr[i + 1][j] && !used[i + 1][j]) {
            if (i + 1 > maxX) maxX = i + 1;
            used[i + 1][j] = true;
            q.push({ i + 1, j });
        }
        if (j > 0 && arr[i][j-1] && !used[i][j-1]) {
            if (j - 1 < minY) minY = j - 1;
            used[i][j-1] = true;
            q.push({ i, j-1 });
        }
        if (j < N-1 && arr[i][j + 1] && !used[i][j + 1]) {
            if (j + 1 > maxY) maxY = j + 1;
            used[i][j + 1] = true;
            q.push({ i, j + 1 });
        }
    }
    return (maxX - minX + 1) * (maxY - minY + 1);
}

int solveStack(int N,int x, int y) {
    int minX=x, maxX=x, minY=y, maxY=y;
    stack<pair<int, int>> st;
    used[x][y] = true;
    st.push({ x,y });
    while (!st.empty())
    {
        pair<int, int> temp = st.top();
        int x = temp.first;
        int y = temp.second;
        st.pop();
        if (x > 0 && arr[x - 1][y] == 1 && !used[x - 1][y]) {
            if (x - 1 < minX)minX = x - 1;
            used[x - 1][y] = true;
            st.push({ x - 1,y });
        }
        if (x < N-1 && arr[x+1][y]==1 && !used[x+1][y]) {
            if (x + 1 > maxX)maxX = x + 1;
            used[x + 1][y] = true;
            st.push({ x + 1,y });
        }
        if (y > 0 && arr[x][y-1] == 1 && !used[x][y-1]) {
            if (y - 1 < minY)minY = y - 1;
            used[x][y-1] = true;
            st.push({ x,y-1 });
        }
        if (y < N-1 && arr[x][y + 1] == 1 && !used[x][y + 1]) {
            if (y + 1 > maxY)maxY = y + 1;
            used[x][y + 1] = true;
            st.push({ x,y + 1 });
        }
    }
    return (maxX - minX + 1) * (maxY - minY + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == 1 && used[i][j] == false) {
                vec.push_back(solveStack(N, i, j));
            }
        }
    }

    sort(vec.begin(),vec.end());

    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
