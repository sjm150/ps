#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[5];
    for (int &a: a) cin >> a;
    for (int i = 4; i; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                for (int a: a) cout << a << ' ';
                cout << '\n';
            }
        }
    }
}