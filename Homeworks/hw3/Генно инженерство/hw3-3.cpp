#include<cmath>
#include<vector>
#include<iostream>
using namespace std;
int rec(long long index, long long l, int p, int& counter) {
    if (p  == 0) return ++counter;
    long long r = l +(long long)(pow(3, p)) - 1;
    if (index < l + (long long)(pow(3, p - 1))) {
        return rec(index, l, p - 1, ++counter);
    }
    else if (index >= l + 2 * ((long long)(pow(3, p - 1)))) {
        return rec(index, l + 2 * ((long long)(pow(3, p - 1))), p-1, ++counter);
    }
    else {
        return ++counter;
    }
}

int main() {
    int n,p;
    cin >> p >> n;
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        long long temp;
        cin >> temp;
        cout << rec(temp-1, 0, p, counter) << '\n';
    }

    return 0;
}
