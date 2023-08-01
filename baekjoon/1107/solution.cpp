#include <iostream>
#include <vector>
using namespace std;

int n;
int nlen;
int close = 100;
int clen = 3;
vector<int> use;

int lenof(int x) {
    int ret = 0;
    while (x) {
        x /= 10;
        ret++;
    }
    return ret;
}

void select(int cur, int sel) {
    if (abs(n - cur) + sel < abs(n - close) + clen) {
        close = cur;
        clen = sel;
    }
    if (sel == nlen + 1) return;
    for (int i: use) select(cur * 10 + i, sel + 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    nlen = lenof(n);
    int m; cin >> m;
    vector<bool> able(10, true);
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        able[b] = false;
    }
    for (int i = 0; i < 10; i++) {
        if (able[i]) use.push_back(i);
    }
    for (int i: use) select(i, 1);
    cout << min(abs(n - 100), abs(n - close) + clen) << '\n';
}