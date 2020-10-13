#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool iseof;
};

struct TrieNode* getnode() {
    struct TrieNode* newNode = new TrieNode;
    for (int i = 0; i < 26; i++) newNode->children[i] = NULL;
    newNode->iseof = false;
    return newNode;
}

void insert(TrieNode* root, string k) {
    struct TrieNode* crawl = root;
    for (int i = 0; i < k.size(); i++) {
        int ind = k[i]-'a';
        if (!crawl->children[ind]) crawl->children[ind] = getnode();
        crawl = crawl->children[ind];
    }
    crawl->iseof = true;
}

bool search(TrieNode* root, string k) {
    struct TrieNode* crawl = root;
    for (int i = 0; i < k.size(); i++) {
        int ind = k[i]-'a';
        if (!crawl->children[ind]) return false;
        crawl = crawl->children[ind];
    }
    return (crawl && crawl->iseof);
}

int main() {
    struct TrieNode* root = getnode();
    insert(root, "om");
    insert(root, "omega");
    cout << search(root, "om") << " " << search(root, "ome")<< " " << search(root,"omega");
    return 0;
}