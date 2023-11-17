#include <iostream> 
#include <vector>
#include <bitset>
#include<set>
#include<climits>
using namespace std;
int result = INT_MAX;
vector<bool> isInArr(1000000000);

void solve(set<int>& set, int n) {
    set.insert(n);
    auto it = set.find(n);
    bool hasPrev = false;
    int cur;
    if (it != set.begin()) {
        it--;
        cur = *(it);
        cur = cur ^ n;
        if (cur < result)result = cur;
        hasPrev = true;
    }
    if (hasPrev) {
        it++;
    }
    it++;
    if (it != set.end()) {
        cur = *(it) ^ n;
        if (cur < result)result = cur;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> set;
    set.insert(0);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {

        int n;
        cin >> n;
        if (isInArr[n] == false) {
            solve(set, n);
            isInArr[n] = true;

        }
        cout << result << "\n";

    }
    return 0;
}