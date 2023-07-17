#include <iostream>

using namespace std;

long long int f(long long int s, long long int k, long long int x) {
    return (s + 20 * x) * (k - 4 * x);
}

long long int vop(long long int s, long long int k) {
    return (5 * k - s) / 40;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long long int s, k;
        cin >> s >> k;
        int r = s % 10;
        long long int maxb = s * k;
        if (r == 0) {
        } else if (r == 5) {
            maxb = max(maxb, (s + 5) * (k - 1));
        } else {
            if (s % 2 == 1) {
                s += s % 10;
                k--;
            }
            for (int i = 0; i < 4; i++) {
                if (k <= 0) break;
                long long int v = vop(s, k);
                maxb = max(maxb, max(s * k, f(s, k, k / 4)));
                if (v > 0) maxb = max(maxb, f(s, k, v));
                if (v > -1) maxb = max(maxb, f(s, k, v + 1));
                s += s % 10;
                k--;
            }
        }
        cout << maxb << '\n';
    }
}