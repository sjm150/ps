#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, b; cin >> n >> b;
    string s = "";
    for (; n; n /= b) {
        int r = n % b;
        if (r < 10) s += r + '0';
        else s += r - 10 + 'A';
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}