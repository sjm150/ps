#include <iostream>

using namespace std;

void print(int x, int y, int n) {
    if (x / n == 1 && y / n == 1) cout << ' ';
    else if (n == 1) cout << '*';
    else print(x % n, y % n, n / 3);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) print(i, j, n / 3);
        cout << '\n';
    }
}