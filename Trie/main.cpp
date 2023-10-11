#include <iostream>
#include <cstring>

using namespace std;
const int MAX_CHAR = 26;

struct trie {
    trie *child[MAX_CHAR];
    bool isLeaf;

    trie() {
        memset(child, 0, sizeof child);
        isLeaf = false;
    }

    void insert(string s, int idx) {
        if (idx == s.size())
            this->isLeaf = true;
        else {
            int realIdx{s[idx] - 'a'};
            if (this->child[realIdx] == nullptr)
                this->child[realIdx] = new trie();
            this->child[realIdx]->insert(s, idx + 1);
        }
    }

    bool search(string s, int idx) {
        if (this == nullptr)
            return false;
        if (idx == s.size() && this->isLeaf)
            return true;
        int realIdx{s[idx] - 'a'};
        if (this->child[realIdx] == nullptr)
            return false;
        return this->child[realIdx]->search(s, idx + 1);
    }

    bool startsWith(string s, int idx) {
        if (this == nullptr)
            return false;
        if (idx == s.size())
            return true;
        int realIdx{s[idx] - 'a'};
        if (this->child[realIdx] == nullptr)
            return false;
        return this->child[realIdx]->startsWith(s, idx + 1);
    }
};

int main() {
    trie *root = new trie();
    root->insert("ashraf", 0);
    root->insert("abc", 0);
    root->insert("abcd", 0);
    root->insert("aa", 0);
    cout << root->search("abcde", 0) << "\n";
    cout << root->search("abcde", 0) << "\n";
    return 0;
}
