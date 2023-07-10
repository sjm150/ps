#include <iostream>

using namespace std;

int num[2000];
int pal[2000][2000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        pal[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        if (num[i] == num[i + 1]) pal[i][i + 1] = 1;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            if (pal[i + 1][i + l - 1] && num[i] == num[i + l]) {
                pal[i][i + l] = 1;
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int b, e;
        cin >> b >> e;
        cout << pal[b - 1][e - 1] << '\n';
    }
}