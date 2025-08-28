#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (;;) {
        int x;
        cin >> x;
        if (!x) break;
        cout << x << " is " << (x % n ? "NOT " : "") << "a multiple of " << n << ".\n";
    }
}