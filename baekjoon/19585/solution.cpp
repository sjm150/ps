#include <bits/stdc++.h>
using namespace std;

typedef struct Trie {
    typedef struct Node {
        bool chk = false;
        vector<pair<char, int>> nxts;
    } node_t;

    vector<node_t> nodes;
    Trie() { nodes.resize(1); }

    void insert(string& s) {
        int cur = 0;
        for (char c: s) {
            int nxt = 0;
            for (auto [_c, _nxt]: nodes[cur].nxts) {
                if (_c == c) {
                    nxt = _nxt;
                    break;
                }
            }
            if (nxt) {
                cur = nxt;
            } else {
                nodes[cur].nxts.emplace_back(c, nodes.size());
                nodes.emplace_back();
                cur = nodes.size() - 1;
            }
        }
        nodes[cur].chk = true;
    }

    int find_next(string& s, int idx, int& cur) {
        for (int i = idx; i < s.size(); i++) {
            int nxt = 0;
            for (auto [_c, _nxt]: nodes[cur].nxts) {
                if (_c == s[i]) {
                    nxt = _nxt;
                    break;
                }
            }
            if (nxt == 0) return -1;
            cur = nxt;
            if (nodes[cur].chk) return i;
        }
        return -1;
    }
} trie_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int c, n; cin >> c >> n;
    trie_t ctrie, ntrie;
    while (c--) {
        string s; cin >> s;
        ctrie.insert(s);
    }
    while (n--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        ntrie.insert(s);
    }

    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        int cur = 0, idx = 0;
        vector<int> lens;
        while (true) {
            idx = ctrie.find_next(s, idx, cur) + 1;
            if (idx == 0) break;
            lens.push_back(idx);
        }

        bool poss = false;
        reverse(s.begin(), s.end());
        cur = idx = 0;
        while (true) {
            idx = ntrie.find_next(s, idx, cur) + 1;
            if (idx == 0) break;
            if (binary_search(lens.begin(), lens.end(), s.size() - idx)) {
                poss = true;
                break;
            }
        }

        if (poss) cout << "Yes\n";
        else cout << "No\n";
    }
}