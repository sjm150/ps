#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a[10];
        for (int &a: a) cin >> a;
        sort(a, a + 10);
        cout << a[7] << '\n';
    }
}