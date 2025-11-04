#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int t = 1;; t++) {
        int n;
        cin >> n;
        if (!n) break;
        cout << t << ". " << (n % 2 ? "odd " : "even ") << n / 2 << '\n';
    }
}