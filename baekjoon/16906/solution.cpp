#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

typedef struct Node {
    bool chk = false;
    int nxt[2] = {0, 0};
} node_t;

vector<node_t> trie(1);

bool insert(int cur, int l, string& s) {
    if (l == 0) {
        trie[cur].chk = true;
        return true;
    }
    for (int i = 0; i < 2; i++) {
        if (trie[trie[cur].nxt[i]].chk) continue;
        if (trie[cur].nxt[i] == 0) {
            trie[cur].nxt[i] = trie.size();
            trie.emplace_back();
        }
        s += i + '0';
        if (!insert(trie[cur].nxt[i], l - 1, s)) return false;
        if (trie[trie[cur].nxt[0]].chk && trie[trie[cur].nxt[1]].chk) trie[cur].chk = true;
        return true;
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pi> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i].first;
        l[i].second = i;
    }
    sort(l.begin(), l.end());

    vector<string> ans(n);
    bool poss = true;
    for (int i = 0; i < n; i++) {
        if (!(poss = insert(0, l[i].first, ans[l[i].second]))) break;
    }

    if (poss) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    } else {
        cout << -1 << '\n';
    }
}