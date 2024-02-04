#include <bits/stdc++.h>
using namespace std;

void print(int n, bool b) {
    if (n) {
        print(--n, b);
        print(n, false);
        print(n, b);
    } else {
        cout << (b ? '-' : ' ');
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        print(n, true);
        cout << '\n';
    }
}