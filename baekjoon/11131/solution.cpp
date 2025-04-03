#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = 0;
        while (n--) {
            int w; cin >> w;
            sum += w;
        }
        cout << (sum > 0 ? "Right" : sum < 0 ? "Left" : "Equilibrium") << '\n';
    }
}