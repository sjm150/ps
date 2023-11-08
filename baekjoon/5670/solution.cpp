#include <bits/stdc++.h>
using namespace std;

typedef struct TrieNode {
    int cnt;
    bool chk;
    vector<int> nxt;
    TrieNode(int cnt): cnt(cnt), chk(false), nxt(vector<int>(26, 0)) {}
} tn_t;

vector<tn_t> trie;

void insert(string& s) {
    int cur = 0;
    for (auto c: s) {
        if (trie[cur].nxt[c - 'a'] == 0) {
            trie[cur].nxt[c - 'a'] = trie.size();
            trie[cur].cnt++;
            trie.push_back(TrieNode(0));
        }
        cur = trie[cur].nxt[c - 'a'];
    }
    trie[cur].chk = true;
}

int pushcnt(string& s) {
    int cur = 0, cnt = 0;
    for (auto c: s) {
        if (trie[cur].cnt >= 2 || trie[cur].chk) cnt++;
        cur = trie[cur].nxt[c - 'a'];
    }
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        vector<string> ss(n);
        trie.clear();
        trie.push_back(TrieNode(2));
        for (int i = 0; i < n; i++) {
            cin >> ss[i];
            insert(ss[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) sum += pushcnt(ss[i]);
        cout << fixed << setprecision(2) << float(sum) / n << '\n';
    }
}