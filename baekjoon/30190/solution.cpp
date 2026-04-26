#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int target[1000001];
int hanoi[1000001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> target[i];
    hanoi[1] = 1;
    for (int i = 2; i <= n; i++) hanoi[i] = (2 * hanoi[i - 1] + 1) % mod;
    int state = k, t = 0;
    for (int i = n; i >= 1; i--) {
        if (target[i] != state) {
            t += hanoi[i - 1] + 1;
            if (t >= mod) t -= mod;
            state = 6 - state - target[i];
        }
    }
    cout << t << '\n';
}