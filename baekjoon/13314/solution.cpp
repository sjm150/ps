#include <iostream>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n = 100;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << 0 << ' ';
            else if (i == n - 1 || j == n - 1) cout << 1 << ' ';
            else cout << 10000 << ' ';
        }
        cout << '\n';
    }
}