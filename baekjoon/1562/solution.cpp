#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;

vector<int> adj[10];
void init_adj() {
    adj[0].push_back(1);
    adj[9].push_back(8);
    for (int i = 1; i <= 8; i++) {
        adj[i].push_back(i - 1);
        adj[i].push_back(i + 1);
    }
}

int cnt[101][10][1024];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n < 10) {
        cout << 0 << '\n';
    } else {
        init_adj();
        for (int i = 1; i <= 9; i++) cnt[1][i][1 << i] = 1;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= 9; i++) {
                for (int p: adj[i]) {
                    for (int b = 0; b < 1024; b++) {
                        int& c = cnt[l][i][b | (1 << i)];
                        c += cnt[l - 1][p][b];
                        if (c >= mod) c -= mod;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= 9; i++) {
            sum += cnt[n][i][1023];
            if (sum >= mod) sum -= mod;
        }
        cout << sum << '\n';
    }
}