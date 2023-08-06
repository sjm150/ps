#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

unordered_map<string, int> idx;
int trip[200];
int cost[100][100];
int rcost[100][100];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, r; cin >> n >> r;
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        idx[name] = i;
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string name; cin >> name;
        trip[i] = idx[name];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = rcost[i][j] = inf;
    for (int i = 0; i < n; i++) cost[i][i] = rcost[i][i] = 0;
    int k; cin >> k;
    while (k--) {
        string t, s, e; cin >> t >> s >> e;
        int c; cin >> c;
        cost[idx[e]][idx[s]] = cost[idx[s]][idx[e]] = min(cost[idx[s]][idx[e]], 2 * c);
        if (t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") rcost[idx[s]][idx[e]] = 0;
        else if (t == "S-Train" || t == "V-Train") rcost[idx[s]][idx[e]] = min(rcost[idx[s]][idx[e]], c);
        else rcost[idx[s]][idx[e]] = min(rcost[idx[s]][idx[e]], 2 * c);
        rcost[idx[e]][idx[s]] = rcost[idx[s]][idx[e]];
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                rcost[i][j] = min(rcost[i][j], rcost[i][k] + rcost[k][j]);
            }
        }
    }

    int tot = 0, rtot = 2 * r;
    for (int i = 1; i < m; i++) {
        tot += cost[trip[i - 1]][trip[i]];
        rtot += rcost[trip[i - 1]][trip[i]];
    }
    if (rtot < tot) cout << "Yes\n";
    else cout << "No\n";
}