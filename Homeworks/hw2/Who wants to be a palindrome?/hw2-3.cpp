#include<string>
#include<vector>
#include<iostream>
using namespace std;
bool canBecomePalindrom(string& str) {
    vector<int> letterArr('z' - 'a'+1);
    for (unsigned i = 0; i < str.length(); i++)
    {
        letterArr[str[i] - 'a']++;
    }
    int oddCounter = 0;
    for (unsigned i = 0; i < letterArr.size(); i++)
    {
        if (letterArr[i] % 2!=0) {
            oddCounter++;
            if (oddCounter > 1) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<string> strVect;
    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        strVect.push_back(str);
    }
    for (int i = 0; i < T; i++)
    {
        if (canBecomePalindrom(strVect[i])) {
            cout << "TRUE\n";
        }
        else {
            cout << "FALSE\n";
        }
    }
    return 0;
}