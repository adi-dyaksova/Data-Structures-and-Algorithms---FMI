//https://www.hackerrank.com/contests/sda-2020-2021-test7-8jfn4/challenges/challenge-2736/problem
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include<set>

using namespace std;

struct  Intervals {
    int y, type;

    Intervals(int y = 0, int type = 0) : y(y), type(type) {}
};
struct CheckLength {
    bool operator()(const Intervals& left, const  Intervals& right) const {
        if (left.y == right.y)
            return left.type > right.type;
        else
            return left.y < right.y;
    }
};
//
//int solve(multiset<pair<int, bool>>& s,int moment) {
//    
//    //int count = 0;
//    int cur = 0;
//    for (auto it = s.begin(); it != s.end(); it++)
//    {
//        if (it->second == true) {
//            cur++;
//        }
//        else {
//            cur--;
//        }
//        //if (count < cur)count = cur;
//        if (it->first == moment)return cur;
//        if (it->first < moment) {
//            it++;
//            if (it!=s.end() && it->first > moment) return cur;
//            else it--;
//        }
//    }
//    return cur;
//    
//}
int getCount(vector<pair<int,int>>& vect, int time) {
    int res = 0;
    for (int i =0;i<vect.size();i++)
    {
        if (vect[i].first<= time && vect[i].second>=time)res++;
    }
    return res;
}

void solve(multiset<pair<int, int>>& s, vector<int>& requests) {
    unordered_map<int,int> ans;
    int count = 0;
    for (auto it:s)
    {
        if (it.second == 1)count++;
        else if (it.second == 3)count--;
        else if (it.second == 2)ans[it.first] = count;
    }

    for (int i = 0; i < requests.size(); i++)
    {
        cout << ans[requests[i]] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int N, Q, i(0), left, right, count(0);
    //cin >> N >> Q;

    //vector<Intervals> inter;
    //inter.reserve(2 * N + Q + 10);

    //queue<int> queries;

    //for (; i < N; ++i)
    //{
    //    cin >> left >> right;
    //    inter.emplace_back(left, 1);
    //    inter.emplace_back(right, -1);
    //}

    //for (i = 0; i < Q; ++i)
    //{
    //    cin >> left;
    //    inter.emplace_back(left);
    //    queries.push(left);
    //}

    //sort(inter.begin(), inter.end(), CheckLength());

    //unordered_map<int, int> ans;

    //N = inter.size();

    //for (i = 0; i < N; ++i)
    //{
    //    count += inter[i].type;
    //    if (!inter[i].type)
    //        ans[inter[i].y] = count;
    //}

    //while (!queries.empty())
    //{
    //    cout << ans[queries.front()] << ' ';
    //    queries.pop();
    //}

    //DUMB SOLUTION
    //int N, Q;
    //cin >> N >> Q;
    ////start end
    //vector<pair<int,int>> vect(N);
    //for (int i = 0; i < N; i++)
    //{
    //    cin >> vect[i].first>>vect[i].second;
    //}
    //int time;
    //for (int i = 0; i < Q; i++)
    //{
    //    cin >> time;
    //    cout << getCount(vect,time) <<" ";
    //}

    //ANOTHER DUMB SOLUTION
    int N, Q;
    cin >> N >> Q;
    multiset<pair<int, int>> s;
    int start, end;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        s.insert({ start,1 });
        s.insert({ end,3 });
    }
    int temp;
    vector<int> requests;
    for (int i = 0; i < Q; i++)
    {
        cin >> temp;
        s.insert({ temp,2 });
        requests.push_back(temp);
    }

    solve(s,requests);
    return 0;
}