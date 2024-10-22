#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int x; cin >> x;
            cnt += x;
        }
        cout << "ABCDE"[(8 - cnt) % 5] << '\n';
    }
}