#include <algorithm>  
#include<vector>
#include<iostream>
using namespace std;
bool hasGreaterInterval(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}
void printCountNotTrustworthy(vector<pair<int, int>>& vect) {
    int counter = 0;
    int min, max;
    min = vect[0].first;
    max = vect[0].second;
    for (long unsigned int i = 1; i < vect.size(); i++)
    {
        if (vect[i].first > max) {
            min = vect[i].first;
            max = vect[i].second;
        }
        else {
            int temp = vect[i].second;
            if (max < temp) {
                max = temp;
            }
            else {
                counter++;
            }
        }
    }
    cout << counter;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
typedef pair<int, int> intPair; 
    int countPairs;
    cin >> countPairs;
    vector<intPair> students;

    for (int i = 0; i < countPairs; i++)
    {
        int a, b;
        cin >> a >> b;
        students.push_back(intPair(a, b));
    }
    sort(students.begin(), students.end(), hasGreaterInterval);
    printCountNotTrustworthy(students);

    return 0;
}