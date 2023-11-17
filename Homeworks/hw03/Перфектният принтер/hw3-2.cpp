#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
long long getCopies(vector<long long>& times, long long seconds) {
    long long copies = 0;
    for (int i = 0; i < times.size(); i++)
    {
        copies += seconds / times[i];
    }
    return copies;
}
 
long long getMinTimeForPrinting(vector<long long>& times, long long l, long long r, long long copies) {
    if (r - l == 1) {
        return r;
    }
    long long mid = (l + r) / 2;
    long long currCopies = getCopies(times, mid);
    if (currCopies >= copies) {
        return getMinTimeForPrinting(times, l, mid, copies);
    }
    else {
        return getMinTimeForPrinting(times, mid, r, copies);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, q;
    cin >> n >> q;
    vector<long long> times(q);
    for (long long i = 0; i < q; i++)
    {
        long long seconds;
        cin >> seconds;
        times[i] = seconds;
    }
    sort(times.begin(), times.end());
    long long maxTime = (ceil(((long double)n/q))) * times[times.size() - 1];
    long long minTime = getMinTimeForPrinting(times, 0, maxTime,n);
    cout << minTime;
    return 0;
}
