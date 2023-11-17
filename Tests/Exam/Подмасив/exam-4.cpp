#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
int A[MAX];

int main() {
     int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    set<int>s;
    int max=0;
    int start =0;
    for(int i=0; i<N; i++){
        int size = s.size();
        s.insert(A[i]);
        if(s.size()!= size){
            if(max<s.size())max = s.size();}
            else{
                while(A[start]!=A[i]){
                    s.erase(A[start]);
                    start++;
                }
            start++;
        }
    }
    cout<<max;
   
    return 0;
}
