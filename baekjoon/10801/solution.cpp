#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[10], b[10];
    for (int &a: a) cin >> a;
    for (int &b: b) cin >> b;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] > b[i]) ans++;
        else if (a[i] < b[i]) ans--;
    }
    if (ans > 0) cout << "A\n";
    else if (ans < 0) cout << "B\n";
    else cout << "D\n";
}