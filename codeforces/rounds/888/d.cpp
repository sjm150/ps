#include <iostream>
using namespace std;
typedef long long ll;

bool used[200001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i <= n; i++) used[i] = false;
        ll prev = 0;
        ll lost = -1;
        bool poss = true;
        for (int i = 0; i < n - 1; i++) {
            ll a; cin >> a;
            ll ori = a - prev;
            if (ori > n || used[ori]) {
                if (lost < 0) lost = ori;
                else poss = false;
            } else {
                used[ori] = true;
            }
            prev = a;
        }
        if (!poss) {
            cout << "NO\n";
        } else if (lost < 0) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) cnt++;
            }
            if (cnt == 1) cout << "YES\n";
            else cout << "NO\n";
        } else {
            for (int i = 1; i <= n; i++) {
                if (!used[i]) lost -= i;
            }
            if (lost == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}