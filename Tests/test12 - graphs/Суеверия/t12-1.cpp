#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int MAX = 2000;
vector<int>matrix[MAX][MAX];
int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> N >> M;
    int v1, v2, w;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> w;
        
        matrix[v1 ][v2 ].push_back(w);
    }
    cin >> K;
    set<int> numbers;
    int temp;
    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        numbers.insert(temp);
    }
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int L,last,next;
        cin >> L>> last;
        bool flag = true;
        for (int j = 0; j < L-1; j++)
        {
            cin >> next;
            bool f = false;
            for (auto x: matrix[last][next]) {
                f = f || numbers.find(x) == numbers.end();
            }
            flag = flag && f;
            last = next;
        }
        cout << (flag) ? 1 : 0;
    }

    return 0;
}