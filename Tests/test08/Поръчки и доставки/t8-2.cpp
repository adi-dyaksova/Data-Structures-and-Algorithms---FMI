#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> hm;
    int n;
    cin >> n;
        for (int i = 0; i < n; i++)
        {
            int id;
            cin >> id;
            if (hm.find(id) == hm.end()) {
                hm[id]=1;
            }
            else {
                hm[id] += 1;
                if (hm[id] == 10)hm[id] = 0;
            }
        }
        int allIDs = 0;
        int allProducts = 0;
        for (auto t : hm) {
            if (t.second != 0) {
                allIDs++;
                allProducts += t.second;
            }
        }
        cout << allIDs << " " << allProducts;

    return 0;
}