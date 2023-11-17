#include<vector>
#include<iostream>
using namespace std;
void PrintMedian(vector<long long>& vect, long long toAdd) {
    int oldSize = vect.size();
    if (vect.size() != 0) {
        for (int i = 0; i < oldSize; i++) //
        {
            if (vect[i] > toAdd) {
                vect.insert(vect.begin()+i,toAdd); //
                break;
            }
            else {
                if (i + 1 == vect.size()) {
                    vect.push_back(toAdd);
                }
            }
            
        }
    }
    else {
        vect.push_back(toAdd);
    }
    if ((vect.size()) % 2 != 0) {
        cout << vect[(vect.size()) / 2];
        cout << '\n';
    }
    else {
        cout << ((double)(vect[(vect.size()) / 2 - 1]) + (double)(vect[(vect.size()) / 2])) / 2.0;
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> vect;
    for (int i = 0; i < N; i++)
    {
        long long temp;
        std::cin >> temp;
        PrintMedian(vect,temp);
    }
    return 0;
}