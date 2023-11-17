#include<iostream>
#include<string>
using namespace std;
const int SIZE = 26;

struct trie
{
    bool isEnd;
    trie* children[SIZE];

    trie() {
        isEnd = false;
        for (int i = 0; i < SIZE; i++)
        {
            children[i] = nullptr;
        }
    }

};

void addWord(trie* root, string& word) {
    trie* temp = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (temp->children[word[i]-'a'] == nullptr) {
            temp->children[word[i] - 'a'] = new trie();
        }
        temp = temp->children[word[i] - 'a'];
    }
    temp->isEnd = true;
}

bool isFound(trie* root, string word) {
    trie* temp = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (temp->children[word[i] - 'a'] == nullptr) {
            return false;
        }
        temp = temp->children[word[i] - 'a'];
    }
    if (temp->isEnd) {
        return true;
    }
    return false;
}


int main() {
    cin.tie(nullptr);

    int N, Q;
    trie* dict = new trie();
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        addWord(dict, word);
        
    }
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string word;
        cin >> word;
        if (isFound(dict,word)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
