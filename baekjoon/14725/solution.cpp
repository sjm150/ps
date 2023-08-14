#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<map<string, int>> trie;
int new_node() {
    trie.push_back(map<string, int>());
    return trie.size() - 1;
}
void insert(vector<string>& foods) {
    int cur = 0;
    for (string& f: foods) {
        if (trie[cur].find(f) == trie[cur].end()) trie[cur][f] = new_node();
        cur = trie[cur][f];
    }
}
void print(int cur, string& indent) {
    for (auto& [f, nxt]: trie[cur]) {
        cout << indent << f << '\n';
        indent += "--";
        print(nxt, indent);
        indent.pop_back();
        indent.pop_back();
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    new_node();
    while (n--) {
        int k; cin >> k;
        vector<string> foods;
        while (k--) {
            string s; cin >> s;
            foods.push_back(s);
        }
        insert(foods);
    }
    string indent = "";
    print(0, indent);
}