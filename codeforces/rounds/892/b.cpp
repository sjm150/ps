#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 1;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int minf = inf, mins = inf;
        ll ssum = 0;
        while (n--) {
            int m; cin >> m;
            int fst = inf, snd = inf;
            while (m--) {
                int a; cin >> a;
                if (fst > a) {
                    snd = fst;
                    fst = a;
                } else if (snd > a) {
                    snd = a;
                }
            }
            minf = min(minf, fst);
            mins = min(mins, snd);
            ssum += snd;
        }
        cout << ssum - mins + minf << '\n';
    }
}