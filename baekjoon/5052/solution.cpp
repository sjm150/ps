#include <iostream>
#include <vector>
using namespace std;

vector<bool> chk;
vector<vector<int>> trie;
int new_node() {
    chk.push_back(false);
    trie.push_back(vector<int>(10, -1));
    return trie.size() - 1;
}
void init() {
    chk = vector<bool>();
    trie = vector<vector<int>>();
    new_node();
}
bool insert(string& s) {
    int cur = 0;
    bool pre = false;
    bool isnew = false;
    for (auto c: s) {
        if (chk[cur]) pre = true;
        if (trie[cur][c - '0'] == -1) {
            isnew = true;
            trie[cur][c - '0'] = new_node();
        }
        cur = trie[cur][c - '0'];
    }
    chk[cur] = true;
    return !pre && isnew;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        init();
        int n; cin >> n;
        bool cons = true;
        while (n--) {
            string s; cin >> s;
            if (cons) {
                if (!insert(s)) cons = false;
            }
        }
        if (cons) cout << "YES\n";
        else cout << "NO\n";
    }
}