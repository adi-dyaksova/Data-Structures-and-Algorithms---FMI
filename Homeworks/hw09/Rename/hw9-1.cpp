#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_map>
#include<set>
#include<map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, int> hm;
    int n;
    cin >> n;
    set<string> prefixes;
    multimap<string, int> names;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        string temp = "";
        bool flag = true;
        for (int i = 0; i < str.size(); i++)
        {


            temp.push_back(str[i]);
            auto p = prefixes.find(temp);
            if (flag &&  p == prefixes.end()) {
                cout << temp << "\n";
                names.insert({ str, 1 });
                flag = false;
            } 
            
            if (flag && temp.size() == str.size()) {
                auto t = names.find(str);
                if (t != names.end()) {
                    t->second++;
                    cout << str <<" "<< t->second << "\n";
                }
                else {
                    cout << str << "\n"; 
                    names.insert({ str, 1 });
                }
                flag = false;
            }
            if (p == prefixes.end()) {
                prefixes.insert(temp);
            }

        }
    }

    return 0;
}