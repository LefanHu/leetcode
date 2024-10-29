#include <string>
using namespace std;

struct TrieNode {
    TrieNode* ch[26];
    bool end;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
        root->end = false;
    }

    void insert(const string& s) {
        TrieNode* it = root;
        for (auto& c : s) {
            if (!it->ch[c - 'a']) {
                it->ch[c - 'a'] = new TrieNode();
            }
            it = it->ch[c - 'a'];
        }
        it->end = true;
    }

    int query(const string& s) {
        TrieNode* it = root;
        for (auto& c : s) {
            if (!it->ch[c - 'a']) return -1;
            it = it->ch[c - 'a'];
        }
        return (it->end)? 1 : 0;
    }
};