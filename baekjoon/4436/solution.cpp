#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll n;
    while (cin >> n) {
        int k = 1;
        set<int> s;
        for (; s.size() < 10; k++) {
            for (ll i = n * k; i; i /= 10) s.insert(i % 10);
        }
        cout << k - 1 << '\n';
    }
}