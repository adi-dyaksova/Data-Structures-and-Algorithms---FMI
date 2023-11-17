#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int calculateShips(int m, int a) {
    return m / (a+1);
}

int getResult(int n, int k, int a) {
    int q;
    int ships = calculateShips(n+1, a);
    set<int> shots;
    shots.insert(0);
    shots.insert(n+1);
    
    cin >> q;
    vector<int> X(q);
    for(int i=0; i<q; i++) cin>>X[i];
    
    int i = 0;
    while (i<q && ships >= k)
    {
        shots.insert(X[i]);
        auto it = shots.find(X[i]);
        
        auto first = it, last = it;
        first--; last++;
        ships -= calculateShips(*last - *first, a);
        ships += calculateShips(X[i] - *first, a);        
        ships += calculateShips(*last - X[i], a);
        i++;
    }
    
    return (ships < k) ? i : -1;
}
int main() {
    int n, k, a;
    cin >> n >> k >> a;
    cout << getResult(n,k,a);
    return 0;
}