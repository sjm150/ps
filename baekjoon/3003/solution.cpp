#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int cnt[] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int n; cin >> n;
        cout << cnt[i] - n << ' ';
    }
    cout << '\n';
}