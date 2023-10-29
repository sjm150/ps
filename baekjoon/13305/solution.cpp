#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> dst(n - 1), cst(n);
    for (int i = 0; i < n - 1; i++) cin >> dst[i];
    for (int i = 0; i < n; i++) cin >> cst[i];

    int cur = 0;
    ll tot = 0;
    while (cur < n - 1) {
        int nxt = cur;
        while (nxt < n - 1 && cst[cur] <= cst[nxt]) {
            tot += ll(dst[nxt]) * cst[cur];
            nxt++;
        }
        cur = nxt;
    }

    cout << tot << '\n';
}