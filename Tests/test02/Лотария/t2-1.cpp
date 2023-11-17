#include <algorithm>  
#include<vector>
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> vect(200000);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vect[temp]++;
    }
    for (int i = 199999; i >= 0; i--)
    {
        if (vect[i] != 0) {
            for (int j = 0; j < vect[i]; j++)
            {
                cout << i << ' ';
            }
        }
    }

    return 0;
}