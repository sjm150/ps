#include <bits/stdc++.h>
using namespace std;

int scr[100];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> scr[i];
    int cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (scr[i] < scr[i + 1]) continue;
        cnt += scr[i] - scr[i + 1] + 1;
        scr[i] = scr[i + 1] - 1;
    }
    cout << cnt << '\n';
}