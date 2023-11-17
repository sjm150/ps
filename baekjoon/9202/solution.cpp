#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> ti;

typedef struct Node {
    int chk, nxt[26];
    Node() {
        chk = -1;
        fill(nxt, nxt + 26, 0);
    }
} node_t;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

vector<node_t> trie(1, Node());
char grid[4][4];

void insert(int idx, string& s) {
    int cur = 0;
    for (char c: s) {
        if (trie[cur].nxt[c - 'A'] == 0) {
            trie[cur].nxt[c - 'A'] = trie.size();
            trie.push_back(Node());
        }
        cur = trie[cur].nxt[c - 'A'];
    }
    trie[cur].chk = idx;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int w; cin >> w;
    vector<string> ss(w);
    vector<bool> used(w);
    for (int i = 0; i < w; i++) {
        cin >> ss[i];
        insert(i, ss[i]);
    }

    int b; cin >> b;
    while (b--) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) cin >> grid[i][j];
        fill(used.begin(), used.end(), false);

        int cnt = 0, ssum = 0;
        string mxl = "";
        queue<ti> q;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (trie[0].nxt[grid[i][j] - 'A'] == 0) continue;
                q.emplace(trie[0].nxt[grid[i][j] - 'A'], i, j, 1 << (4 * i + j));
            }
        }

        while (!q.empty()) {
            auto [node, x, y, vst] = q.front(); q.pop();

            int si = trie[node].chk;
            if (si >= 0 && !used[si]) {
                used[si] = true;
                cnt++;
                ssum += score[ss[si].size()];
                if (mxl.size() < ss[si].size()) mxl = ss[si];
                else if (mxl.size() == ss[si].size() && mxl > ss[si]) mxl = ss[si];
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || 4 <= nx || ny < 0 || 4 <= ny) continue;
                if (trie[node].nxt[grid[nx][ny] - 'A'] == 0 || ((vst >> (4 * nx + ny)) & 1)) continue;
                q.emplace(trie[node].nxt[grid[nx][ny] - 'A'], nx, ny, vst | (1 << (4 * nx + ny)));
            }
        }

        cout << ssum << ' ' << mxl << ' ' << cnt << '\n';
    }
}