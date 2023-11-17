#include <bits/stdc++.h>
using namespace std;

typedef struct TrieNode {
    int cnt;
    int nxt[26];
    TrieNode() {
        cnt = 0;
        fill(nxt, nxt + 26, 0);
    }
} tn_t;

typedef struct Trie {
    vector<tn_t> nodes;
    Trie() {
        nodes.push_back(TrieNode());
    }

    void insert(string& s) {
        int cur = 0;
        bool printed = false;
        for (int i = 0; i < s.size(); i++) {
            if (nodes[cur].nxt[s[i] - 'a'] == 0) {
                nodes[cur].nxt[s[i] - 'a'] = nodes.size();
                nodes.push_back(TrieNode());
                if (!printed) {
                    for (int j = 0; j <= i; j++) cout << s[j];
                    cout << '\n';
                    printed = true;
                }
            }
            cur = nodes[cur].nxt[s[i] - 'a'];
        }
        nodes[cur].cnt++;

        if (!printed) {
            cout << s;
            if (nodes[cur].cnt > 1) cout << nodes[cur].cnt;
            cout << '\n';
        }
    }
} trie_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    trie_t trie;
    while (n--) {
        string s; cin >> s;
        trie.insert(s);
    }
}