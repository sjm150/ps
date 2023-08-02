#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<string, int> idx;
string names[1000];
vector<int> edges[1000];
int indeg[1000];
vector<int> childs[1000];
vector<int> roots;
bool cmp(int a, int b) {
    return names[a] < names[b];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        idx[names[i]] = i;
    }
    int m; cin >> m;
    while (m--) {
        string x, y; cin >> x >> y;
        edges[idx[y]].push_back(idx[x]);
        indeg[idx[x]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            roots.push_back(i);
        }
    }
    cout << roots.size() << '\n';
    sort(roots.begin(), roots.end(), cmp);
    for (int r: roots) cout << names[r] << ' ';
    cout << '\n';

    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (int d: edges[a]) {
            indeg[d]--;
            if (indeg[d] == 0) {
                childs[a].push_back(d);
                q.push(d);
            }
        }
    }
    for (auto it = idx.begin(); it != idx.end(); it++) {
        int i = it->second;
        cout << it->first << ' ';
        cout << childs[i].size();
        sort(childs[i].begin(), childs[i].end(), cmp);
        for (int c: childs[i]) cout << ' ' << names[c];
        cout << '\n';
    }
}