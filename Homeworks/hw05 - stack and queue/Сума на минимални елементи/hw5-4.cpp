#include<iostream>
#include<queue>
using namespace std;


long long getSum(int* arr, int N, int d)
{
    long long sum = 0;
    std::deque<int> deq(d);

    int i;
    for (i = 0; i < d; ++i)
    {

        while ((!deq.empty()) && arr[i] <= arr[deq.back()]) {
            deq.pop_back();
        }
        
        deq.push_back(i);
    }

    
    for (; i < N; ++i)
    {
        sum += (long long)arr[deq.front()];

        while ((!deq.empty()) && deq.front() <= i - d) {
            deq.pop_front();
        }

        while ((!deq.empty()) && arr[i] <= arr[deq.back()]) {
            deq.pop_back();
        }
        deq.push_back(i);
    }
    sum += (long long)arr[deq.front()];
    return sum;
}

int main()
{
    int N, d;
    cin >> N >> d;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    cout<< getSum(arr, N, d);
    return 0;
}