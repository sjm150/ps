#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int inf = 1e7;
const int mxk = 17;

typedef struct Node {
    int anc, minw, maxw;
    Node(): anc(0), minw(inf), maxw(0) {}
    Node(int anc, int w): anc(anc), minw(w), maxw(w) {}
    Node(struct Node& a, struct Node& b): anc(a.anc), minw(min(a.minw, b.minw)), maxw(max(a.maxw, b.maxw)) {}
} node_t;

vector<vector<pi>> edges;
vector<int> h;
vector<vector<node_t>> stbl;

void init(int pre, int cur, int w) {
    stbl[0][cur] = Node(pre, w);
    for (int i = 1; i < mxk; i++) {
        int anc = stbl[i - 1][cur].anc;
        if (stbl[i - 1][anc].anc == 0) break;
        stbl[i][cur] = Node(stbl[i - 1][anc], stbl[i - 1][cur]);
    }
    for (auto &[w, nxt]: edges[cur]) {
        if (nxt == pre) continue;
        h[nxt] = h[cur] + 1;
        init(cur, nxt, w);
    }
}

pi get(int u, int v) {
    if (h[u] < h[v]) return get(v, u);
    int minw = inf, maxw = 0;

    int dh = h[u] - h[v];
    for (int i = 0; dh; i++) {
        if (dh % 2) {
            minw = min(minw, stbl[i][u].minw);
            maxw = max(maxw, stbl[i][u].maxw);
            u = stbl[i][u].anc;
        }
        dh /= 2;
    }
    if (u == v) return {minw, maxw};

    for (int i = mxk - 1; i >= 0; i--) {
        if (stbl[i][u].anc == stbl[i][v].anc) continue;
        minw = min(minw, min(stbl[i][u].minw, stbl[i][v].minw));
        maxw = max(maxw, max(stbl[i][u].maxw, stbl[i][v].maxw));
        u = stbl[i][u].anc;
        v = stbl[i][v].anc;
    }

    return {min(minw, min(stbl[0][u].minw, stbl[0][v].minw)), max(maxw, max(stbl[0][u].maxw, stbl[0][v].maxw))};
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }

    stbl.resize(mxk, vector<node_t>(n + 1));
    h.resize(n + 1);
    h[1] = 0;
    init(0, 1, 0);

    int k; cin >> k;
    while (k--) {
        int d, e; cin >> d >> e;
        auto [minw, maxw] = get(d, e);
        cout << minw << ' ' << maxw << '\n';
    }
}