#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool neg = false;
        int pcnt = 0, ncnt = 0;
        while (n--) {
            int a; cin >> a;
            if (a > 0) {
                pcnt++;
                neg = false;
            } else {
                if (!neg) ncnt++;
                neg = true;
            }
        }
        if (pcnt > ncnt) cout << "YES\n";
        else cout << "NO\n";
    }
}