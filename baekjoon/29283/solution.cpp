#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    int q = k / 5, r = k % 5;
    cout << q * ll(q + 1) / 2 * 150 + ll(q + 1) * 30 * r << '\n';
}