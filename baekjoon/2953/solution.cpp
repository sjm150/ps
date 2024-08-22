#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int s[5] = {};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int v; cin >> v;
            s[i] += v;
        }
    }
    auto mx = max_element(s, s + 5);
    cout << mx - s + 1 << ' ' << *mx << '\n';
}