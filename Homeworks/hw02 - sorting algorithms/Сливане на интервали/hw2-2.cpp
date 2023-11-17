#include <algorithm>  
#include<vector>
#include<iostream>
using namespace std;
bool isSmaller(pair<int,int>& a, pair<int,int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

void printIntervals(vector<pair<int,int>>& vect) {
      vector<pair<int, int>> newVect;
    int min, max;
    min = vect[0].first;
    max = vect[0].second;
    for (long unsigned int i = 1; i < vect.size(); i++)
    {
        if (vect[i].first > max) {
            newVect.push_back(make_pair(min, max));
            min = vect[i].first;
            max = vect[i].second;
        }
        else {
            int temp = vect[i].second;
            max = (max > temp) ? max : temp;
        }
        
    }
     newVect.push_back(make_pair(min, max));
    for (long unsigned int i = 0; i < newVect.size(); i++)
    {
        cout << newVect[i].first << " " << newVect[i].second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    typedef pair<int, int> intPair;
    int countPairs;
    cin >> countPairs;
    vector<intPair> vect;
    for (int i = 0; i < countPairs; i++)
    {
        int a, b;
        cin >> a >> b;
        vect.push_back(intPair(a, b));
    }
    sort(vect.begin(), vect.end(), isSmaller);
    printIntervals(vect);
    return 0;
}