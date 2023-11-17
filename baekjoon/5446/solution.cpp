#include <bits/stdc++.h>
using namespace std;

typedef struct Trie {
    typedef struct Node {
        bool del = false, prt = false;
        vector<pair<char, int>> nxt;
    } node_t;

    vector<node_t> nodes;
    Trie(): nodes(vector<node_t>(1)) {}

    void insert(string& s) {
        int cur = 0;
        for (char c: s) {
            int nxt = 0;
            for (auto [_c, _nxt]: nodes[cur].nxt) {
                if (_c == c) {
                    nxt = _nxt;
                    break;
                }
            }
            if (nxt == 0) {
                nxt = nodes.size();
                nodes.emplace_back();
                nodes[cur].nxt.emplace_back(c, nxt);
            }
            cur = nxt;
        }
        nodes[cur].del = true;
    }

    void protect(string& s) {
        int cur = 0;
        for (char c: s) {
            nodes[cur].prt = true;
            int nxt = 0;
            for (auto [_c, _nxt]: nodes[cur].nxt) {
                if (_c == c) {
                    nxt = _nxt;
                    break;
                }
            }
            if (nxt == 0) break;
            cur = nxt;
        }
        nodes[cur].prt = true;
    }

    int dfs(int cur) {
        if (!nodes[cur].prt) return 1;
        int res = nodes[cur].del;
        for (auto [_c, nxt]: nodes[cur].nxt) res += dfs(nxt);
        return res;
    }
} trie_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        trie_t trie;
        while (n--) {
            string s; cin >> s;
            trie.insert(s);
        }
        cin >> n;
        while (n--) {
            string s; cin >> s;
            trie.protect(s);
        }
        cout << trie.dfs(0) << '\n';
    }
}