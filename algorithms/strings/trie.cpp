#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char c) { return (links[c-'a'] != NULL); }
    void put(char c, Node* node) { links[c-'a']=node; }
    Node* get(char c) { return links[c-'a']; }
    void setEnd() { flag=true; }
    bool isEnd() { return flag; }
};

class Trie {
    private: Node* root;
    public:

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); ++i) {
            if(!node->containsKey(word[i])) node->put(word[i], new Node());
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); ++i) {
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string pref) {
        Node* node = root;
        for(int i = 0; i < pref.length(); ++i) {
            if(!node->containsKey(pref[i])) return false;
            node=node->get(pref[i]);
        }
        return true;
    }

};
