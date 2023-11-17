#include<iostream>
#include <cmath>
using namespace std;
void printNewArray(long long* arr, unsigned N) {
    long long* leftArr = new long long[N];
    long long* rightArr = new long long[N];
    int temp = pow(10.0, 9.0) + 7;

    leftArr[0] = 1;
    for (unsigned i = 0; i < N-1; i++)
    {
        leftArr[i + 1] = (leftArr[i] * arr[i])%temp;
    }
    //for (unsigned i = 0; i < N; i++)
    //{
    //    cout << leftArr[i];
    //    cout << " ";
    //}
    //cout << endl;

    rightArr[N - 1] = 1;
    for (unsigned i = N-1; i > 0; i--)
    {
        rightArr[i - 1] = (rightArr[i] * arr[i])%temp;
    }
    /*for (unsigned i = 0; i < N; i++)
    {
        cout << rightArr[i];
        cout << " ";
    }
    cout << endl;*/

    for (unsigned i = 0; i < N; i++)
    {
        cout << (long long)((leftArr[i] * rightArr[i])%temp);
        cout << ' ';
    }

    delete[] leftArr;
    delete[] rightArr;
}

int main() {
    cin.tie(nullptr);
    unsigned N;
    cin >> N;
    long long* arr = new long long[N];
    for (unsigned i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        arr[i] = num;
    }

    printNewArray(arr, N);

    return 0;
}