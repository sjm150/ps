#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nxt;
int new_node() {
    nxt.push_back(vector<int>(26, -1));
    return nxt.size() - 1;
}
void insert(string& s) {
    int cur = 0;
    for (auto c: s) {
        if (nxt[cur][c - 'a'] == -1) nxt[cur][c - 'a'] = new_node();
        cur = nxt[cur][c - 'a'];
    }
}
bool find(string& s) {
    int cur = 0;
    for (auto c: s) {
        if (nxt[cur][c - 'a'] == -1) return false;
        cur = nxt[cur][c - 'a'];
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    new_node();
    int n, m; cin >> n >> m;
    while (n--) {
        string s; cin >> s;
        insert(s);
    }
    int cnt = 0;
    while (m--) {
        string s; cin >> s;
        if (find(s)) cnt++;
    }
    cout << cnt << '\n';
}