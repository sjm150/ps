#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<map<string, int>> trie;
int new_node() {
    trie.push_back(map<string, int>());
    return trie.size() - 1;
}
void insert(vector<string>& path) {
    int cur = 0;
    for (string& dir: path) {
        if (trie[cur].find(dir) == trie[cur].end()) trie[cur][dir] = new_node();
        cur = trie[cur][dir];
    }
}
void print(int cur, string& indent) {
    for (auto& [dir, nxt]: trie[cur]) {
        cout << indent << dir << '\n';
        indent.push_back(' ');
        print(nxt, indent);
        indent.pop_back();
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    new_node();
    while (n--) {
        string s; cin >> s;
        vector<string> path;
        string cur = "";
        for (auto c: s) {
            if (c == '\\') {
                path.push_back(cur);
                cur = "";
            } else {
                cur += c;
            }
        }
        path.push_back(cur);
        insert(path);
    }
    string indent = "";
    print(0, indent);
}