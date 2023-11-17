#include<iostream>
using namespace std;
int getDistance(char* arr, unsigned N) {
    unsigned counter = 0;
    unsigned maxCount = 0;
    int distance = -1;
    bool isUttermost = false;
    int index = -1;

    for (unsigned i = 0; i < N; i++)
    {
        if (arr[i] == '-') {
            counter++;
            if (i + 1 == N && counter > maxCount) {
                isUttermost = true;
                maxCount = counter;
                index = i - counter;
            }
        }
        else {
            if (counter > maxCount) {
                maxCount = counter;
                index = i - counter;
            }
            counter = 0;
        }
    }
    if (index == 0)isUttermost = true;

    if (maxCount < 1) {
        distance = -1;
    }
    else {
        if (isUttermost) {
            distance = maxCount - 1;
        }
        else {
            distance = maxCount / 2;
            if (maxCount % 2 == 0) {
                distance -= 1;
            }
        }

    }
    return distance;
}
int main() {
    cin.tie(nullptr);
        unsigned N;
    cin >> N;
    char* arr = new char[N+1]; //or N+1
    arr[N] = '\0';
    for (unsigned i = 0; i < N; i++)
    {
        char symbol;
        cin >> symbol;
        arr[i] = symbol;
    }

    cout << getDistance(arr, N);
    return 0;
}