#include <bits/stdc++.h>
using namespace std;

const int mx = 40000;
vector<bool> poss[2];

int cur = 0, nxt = 1;
void swap() {
    cur = 1 - cur;
    nxt = 1 - nxt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    poss[cur] = poss[nxt] = vector<bool>(mx + 1, false);
    poss[cur][0] = true;
    while (n--) {
        int w; cin >> w;
        for (int j = 0; j <= mx - w; j++) {
            if (poss[cur][j]) {
                poss[nxt][j] = true;
                poss[nxt][abs(j - w)] = true;
                poss[nxt][j + w] = true;
            }
        }
        swap();
    }
    cin >> n;
    while (n--) {
        int w; cin >> w;
        cout << (poss[cur][w] ? "Y " : "N ");
    }
    cout << '\n';
}