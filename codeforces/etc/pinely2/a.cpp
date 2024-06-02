#include <iostream>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, a, q; cin >> n >> a >> q;
        int ccnt, mcnt, pcnt;
        ccnt = mcnt = pcnt = a;
        while (q--) {
            char c; cin >> c;
            if (c == '+') {
                ccnt++;
                pcnt++;
                if (ccnt > mcnt) mcnt = ccnt;
            } else {
                ccnt--;
                if (ccnt < 0) ccnt = 0;
            }
        }
        if (mcnt >= n) cout << "YES\n";
        else if (pcnt >= n) cout << "MAYBE\n";
        else cout << "NO\n";
    }
}