#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, maxx = -1, maxi = 0, maxj = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> x;
            if (maxx < x) {
                maxx = x;
                maxi = i;
                maxj = j;
            }
        }
    }
    cout << maxx << '\n' << maxi << ' ' << maxj << '\n';
}