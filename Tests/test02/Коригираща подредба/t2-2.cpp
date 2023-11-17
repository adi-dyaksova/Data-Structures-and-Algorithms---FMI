#include<vector>
#include<iostream>
using namespace std;
void merge(vector<int>& vect, int l, int middle, int r) {
    vector<int> first;
    vector<int> second;
    for (int i = l; i <= middle; i++)
    {
        first.push_back(vect[i]);
    }
    for (int i = middle + 1; i <= r; i++)
    {
        second.push_back(vect[i]);
    }
    int i = 0, j = 0;
    int index = l;
    while (i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            vect[index] = first[i];
            index++;
            i++;
        }
        else {
            vect[index] = second[j];
            index++;
            j++;
        }
    }
    while (i < first.size()) {
        vect[index] = first[i];
        index++;
        i++;
    }
    while (j < second.size()) {
        vect[index] = second[j];
        index++;
        j++;
    }
}
void merge_sort(vector<int>& vect, int l, int r) {
    if (r - l <= 0) {
        return;
    }
    int middle = (l + r) / 2;
    merge_sort(vect, l, middle);
    merge_sort(vect, middle + 1, r);
    merge(vect, l, middle, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }
    merge_sort(vect, 0, vect.size() - 1);
    
    for (int i = 0; i < vect.size(); i++)
    {
        if (i == 0 || vect[i] != vect[i - 1]) {
            cout << vect[i] << ' ';
        }
        
    }
    return 0;
}