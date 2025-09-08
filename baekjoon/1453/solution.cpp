#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bool> used(n, false);
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        x--;
        if (used[x]) ans++;
        else used[x] = true;
    }
    cout << ans << '\n';
}