#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;
const int MAX = 1000000;
vector<int> graph[MAX];
int used[MAX];
int N,M;
void dfs(int i, int k){
    stack<int> s;
    s.push(i);
    while(!s.empty()){
        int x = s.top();
        s.pop();
        used[x] = k;
        for(auto y: graph[x]){
            if(used[y]==0){
                s.push(y);
            }
        }
    }
}

int main() {
    cin>>N>>M;
    vector<int> res;

        int v1,v2;
    for(int i =0; i<M;i++){      
       cin>>v1>>v2;
       v1--;v2--;
       graph[v1].push_back(v2);
       graph[v2].push_back(v1);
    }
    int k =0;
    for (int i =0; i<N;i++){
        if(used[i]==0){
            k++;
            dfs(i,k);
        }
    }
     
    int q;
    cin>>q;
    int t1,t2;
     for(int i =0; i<q;i++){ 
         cin>>t1>>t2;
         t1--;t2--;
         if(used[t1]==used[t2]){
              res.push_back(1); 
         }
         else   res.push_back(0); 
        
     }
     for(int i =0; i<res.size();i++){ 
         cout<<res[i]<<" ";
     }
    return 0;
}