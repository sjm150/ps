#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) cout << ' ';
        for (int j = 0; j < i - 1; j++) cout << '*';
        cout << '*';
        for (int j = 0; j < i - 1; j++) cout << '*';
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - i; j++) cout << ' ';
        for (int j = 0; j < i - 1; j++) cout << '*';
        cout << '*';
        for (int j = 0; j < i - 1; j++) cout << '*';
        cout << '\n';
    }
}