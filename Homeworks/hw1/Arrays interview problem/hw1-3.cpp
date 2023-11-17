#include<iostream>
#include <cmath>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int getMissingNum(int* arr, int N) {
    int missing = 1;
    for (int i = 0; i < N; i++)
    {
        while (arr[i] > 0 && arr[i] < N && arr[i]!=arr[arr[i]]) {
            swap(arr[i], arr[arr[i]]);
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (arr[i]!=i && i!=1 && arr[i - 1] == (i - 1)) {
            missing = arr[i-1]+1;
            break;
        }
    }
    return missing;
}

int main() {
    cin.tie(nullptr);
    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    cout<<getMissingNum(arr, N);
    return 0;
}