#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

long long getInd(vector<long long>& vect, long long l, long long r, long long num) {
    while (l <= r) {
        long long midInd = (l + r) / 2;
        if (vect[midInd] > num) {
            r = midInd - 1;
        }
        else if (vect[midInd] < num) {

            l = midInd + 1;
        }
        else return midInd;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    cin >> N;
    vector<long long> vect(N);
    for (long long i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        vect[i] = temp;
    }
    long long min = 0;
    for (long long i = 1; i < N; i++)
    {
        if (vect[min] > vect[i])min = i;
    }
    sort(vect.begin(), vect.end());
    long long q;
    cin >> q;
    for (long long i = 0; i < q; i++)
    {
        long long num;
        cin >> num;
        if((getInd(vect, 0, vect.size()-1, num)) == -1){
            cout << -1 << '\n';
        }
        else{
            long long result = (getInd(vect, 0, vect.size()-1, num)+min)%(vect.size());
        cout << result << '\n';}
    }
    return 0;
}