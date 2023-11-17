#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int getMaxCountNumbers(vector<int>& vect, int lastIndex, int maxSum, vector<int>& sums) {
    int counterNums = maxSum / vect[lastIndex]; //15/6 = 2
    if (counterNums > lastIndex) {
        return vect.size() - (vect.size()-(lastIndex+1));
    }
    int sum = sums[lastIndex] - sums[lastIndex - counterNums];//
    lastIndex -= counterNums;
    while (lastIndex >= 0 && sum + vect[lastIndex] <= maxSum) {
        sum += vect[lastIndex];
        lastIndex--;
        counterNums++;
    }
    return counterNums;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> vect(n);
    
    for (int i = 0; i < n; i++)
    {
        int temp;
         cin >> temp;
        vect[i] = temp;
    }
    sort(vect.begin(), vect.end());    
    vector<int> sums(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += vect[i];
        sums[i] = sum;
    }

    int arr[200001] = {};
    int curr = 0;

    for (int i = 0; i < 200001; i++)
    {
        while (curr < n && vect[curr] <= i) {
            curr++;
        }
            arr[i] = curr - 1;;    
    }

    for (int i = 0; i < q; i++)
    {
        int S, P;
        cin >> S >> P;
        if (P < vect[0]) {
            printf("%i \n", 0);
        }
        else {
           
            int maxCount = getMaxCountNumbers(vect, arr[P], S,sums);
            printf("%i \n", maxCount);
        }
    }
    return 0;
}