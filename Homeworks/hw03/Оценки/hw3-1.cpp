#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int getLowerIndex(vector<int>& grades, int l, int r, int a) {
    while (l < r) {
        int midInd = (l + r) / 2;
        if (grades[midInd] > a) {
           
            r = midInd - 1;
        }
        else if (grades[midInd] < a) {
           
            l = midInd + 1;
        }
        else return midInd;
    }
    if (grades[l] < a) {
        if (l < grades.size() - 1) {
            return l + 1;
        }
        else return -1;
    }
    return l;
}

int getUpperIndex(vector<int>& grades, int l, int r, int b) {
    while (l < r) {
        int midInd = (l + r) / 2;
        if (grades[midInd] > b) {
           
            r = midInd - 1;
        }
        else if (grades[midInd] < b) {
           
            l = midInd + 1;
        }
        else return midInd;
    }

    if (grades[l] <= b) {
        return l;
    }
    else {
        return l - 1;
    }

    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //TASK 1
    int n,q;
    cin >> n >> q;
    vector<int> grades;
    for (int i = 0; i < n; i++)
    {
        int grade;
        cin >> grade;
        grades.push_back(grade);
    }
    sort(grades.begin(),grades.end());

    for (int i = 0; i < q; i++)
    {
        int start,end;
        cin >> start >> end;
        if(start>end){
          cout<< 0 <<'\n';
          continue;
      }

        int lowerIndex, upperIndex;
        if (start <= grades[0]) {
            lowerIndex = 0;
        }
        else {
             int ind = getLowerIndex(grades, 0, grades.size() - 1, start);
             while (ind > 0 && grades[ind] == grades[ind-1]) {
                 ind--;
             }
             lowerIndex = ind;
        }
        if (end >= grades[grades.size() - 1]) {
            upperIndex = grades.size() - 1;
        }
        else {
            int ind = getUpperIndex(grades, 0, grades.size() - 1, end);
            while (ind < grades.size()-1 && grades[ind]==grades[ind+1]) {
                ind++;
            }
            upperIndex = ind;
        }
        if (upperIndex==-1 || lowerIndex==-1 ||upperIndex < lowerIndex) {
            cout << 0 <<'\n';
        }
        else {
            cout << upperIndex - lowerIndex + 1 << '\n';
        }
    }
    return 0;
}