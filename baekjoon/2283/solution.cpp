#include <iostream>
#include <algorithm>
typedef long long lint;
using namespace std;

pair<int, bool> edges[2000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        edges[2 * i] = {s, true};
        edges[2 * i + 1] = {e, false};
    }
    sort(edges, edges + 2 * n);
    int l = 0, r = 0;
    int lidx = 0, ridx = 0;
    int lcnt = 0, rcnt = 0;
    int total = 0;
    do {
        if (total == k) {
            cout << l << ' ' << r << '\n';
            return 0;
        } else if (total < k) {
            while (ridx < 2 * n && edges[ridx].first == r) {
                if (edges[ridx].second) rcnt++;
                else rcnt--;
                ridx++;
            }
            r++;
            total += rcnt;
        } else {
            while (lidx < 2 * n && edges[lidx].first == l) {
                if (edges[lidx].second) lcnt++;
                else lcnt--;
                lidx++;
            }
            l++;
            total -= lcnt;
        }
    } while (r <= 1e6 + 1);
    cout << "0 0\n";
}