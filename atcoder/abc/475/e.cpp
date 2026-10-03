#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int cnt = 0, nxt[2] = {-1, -1};
} node_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    string t;
    cin >> t;
    vector<string> s(n);
    for (auto &s: s) cin >> s;

    vector<node_t> trie(1);
    auto add = [&](string &s, int v) {
        for (int i = 0, cur = 0; i < k; i++) {
            bool b = s[i] == t[i];
            if (trie[cur].nxt[b] < 0) {
                trie[cur].nxt[b] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[b];
            trie[cur].cnt += v;
        }
    };
    auto chk = [&](string &s) {
        for (int i = 0, cur = 0, sum = 0; 0 <= cur && i < k; i++) {
            bool b = s[i] == t[i];
            int ocnt = trie[cur].nxt[1] < 0 ? 0 : trie[trie[cur].nxt[1]].cnt;
            if (sum + ocnt <= m) {
                if (b) return true;
                sum += ocnt;
                cur = trie[cur].nxt[0];
            } else {
                if (!b) return false;
                cur = trie[cur].nxt[1];
            }
        }
        return false;
    };
    for (auto &s: s) add(s, 1);

    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;

        add(s[i], -1);
        s[i][j] = 'o' + 'x' - s[i][j];
        add(s[i], 1);
        cout << (chk(s[i]) ? "Yes\n" : "No\n");
    }
}