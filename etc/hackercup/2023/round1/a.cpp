#include <bits/stdc++.h>
using namespace std;

int n;
int x[100000];

double solve() {
    sort(x, x + n);
    if (n == 5) {
        return max(
            double(x[n - 1] + x[n - 2]) / 2 - double(x[0] + x[2]) / 2,
            double(x[n - 1] + x[n - 3]) / 2 - double(x[0] + x[1]) / 2
        );
    } else {
        return double(x[n - 1] + x[n - 2]) / 2 - double(x[0] + x[1]) / 2;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> x[i];
        cout << fixed << setprecision(2);
        cout << "Case #" << testcase << ": " << solve() << '\n';
    }
}