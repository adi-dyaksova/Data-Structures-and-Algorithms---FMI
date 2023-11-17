#include<iostream>
using namespace std;

unsigned getProfit(unsigned* arr, unsigned size) {
    if (arr == nullptr) {
        return 0;
    }
    bool isSelling = false;
    unsigned profit = 0;
    unsigned buy, sell;
    if (size > 1) {
        for (unsigned i = 0; i < size; i++)
        {
            if (i + 1 == size && isSelling) {
                    sell = arr[i];
                    profit += sell - buy;
            }
            else {
                if (isSelling == false && arr[i] < arr[i + 1]) {
                    buy = arr[i];
                    isSelling = true;
                }
                else if (isSelling == true && arr[i] > arr[i + 1]) {
                    sell = arr[i];
                    profit += sell - buy;
                    isSelling = false;
                }
            }
        }
    }
    return profit;
}

int main() {
    cin.tie(nullptr);
    unsigned N;
    cin >> N;
    unsigned* arr = new unsigned[N];

    for (unsigned i = 0; i < N; i++)
    {
        unsigned temp;
        cin >> temp;
        arr[i] = temp;
    }
    cout << getProfit(arr, N);
    
    return 0;
}