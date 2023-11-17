#include <iostream> 
#include <vector>
#include <bitset>
#include<set>
using namespace std;

int main() {
    int N; cin >> N;
    set<string> setOfMasks;

    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        vector<string> masks;
        string binary = std::bitset<21>(num).to_string();
        string insert = string(binary.size(), '0');
        masks.push_back(insert);
        setOfMasks.insert(insert);

        int counter = 0;
        while (counter < binary.size()) {
            if (binary[counter] == '1') {
                size_t masksSize = masks.size();
                for (size_t j = 0; j < masksSize; j++) {
                    string toInsert = masks[j];
                    toInsert[counter] = '1';
                    masks.push_back(toInsert);
                    setOfMasks.insert(toInsert);
                }
            }
            counter++;
        }
    }
    cout << setOfMasks.size();
    return 0;
}