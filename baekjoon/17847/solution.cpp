#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = 1;
    while (n * n < s.size()) n++;
    
    const int dx[] = {-1, 1, 1, -1};
    const int dy[] = {1, 1, -1, -1};

    for (int d = 0; d < n / 2; d++) {
        int x = n / 2, y = d;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n / 2 - d; j++) {
                cout << s[x * n + y];
                x += dx[i], y += dy[i];
            }
        }
    }
    cout << s[s.size() / 2] << '\n';
}