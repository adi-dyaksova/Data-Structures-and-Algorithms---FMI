#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
bool solve(vector<int>& v)
{

    unordered_set<int> s;
    for (int j = 1; j < v.size(); j++)
    {
        if (s.find(v[j]) != s.end()) {
            return true;
        }
        for (int i = 0; i < j; i++)
        {
            s.insert(v[i] + v[j]);
            
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v[i] = temp;
    }
    sort(v.begin(), v.end());
    if (solve(v)) {
        cout << "true";
    }
    else {
        cout << "false";
    }


    return 0;
}