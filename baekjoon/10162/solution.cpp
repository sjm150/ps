#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    if (t % 10) {
        cout << -1 << '\n';
    } else {
        cout << t / 300 << ' ';
        t %= 300;
        cout << t / 60 << ' ';
        t %= 60;
        cout << t / 10 << '\n';
    }
}