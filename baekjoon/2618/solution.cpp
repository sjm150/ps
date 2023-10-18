#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

struct { int x, y; } crd[1002];
struct { int p, d; } sumd[1002][1000];

int dst(int i, int j) {
    return abs(crd[i].x - crd[j].x) + abs(crd[i].y - crd[j].y);
}

int print_back(int o, int i) {
    if (i == 0) {
        cout << sumd[o][i].p << '\n';
        return sumd[o][i].p;
    }
    int mvd = print_back(sumd[o][i].p, i - 1);
    if (sumd[o][i].p != o) mvd = 3 - mvd;
    cout << mvd << '\n';
    return mvd;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, w; cin >> n >> w;
    for (int i = 0; i < w; i++) cin >> crd[i].x >> crd[i].y;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j <= w + 1; j++) {
            sumd[j][i].d = inf;
        }
    }
    crd[w] = {1, 1};
    crd[w + 1] = {n, n};
    sumd[w][0] = {2, dst(0, w + 1)};
    sumd[w + 1][0] = {1, dst(0, w)};
    for (int i = 1; i < w; i++) {
        for (int j = 0; j <= w + 1; j++) {
            int d = sumd[j][i - 1].d;
            if (d == inf) continue;
            for (int oth: {i - 1, j}) {
                int nd = d + dst(i, i - 1 + j - oth);
                if (sumd[oth][i].d > nd) sumd[oth][i] = {j, nd};
            }
        }
    }
    int mini = 0;
    for (int i = 1; i <= w + 1; i++) {
        if (sumd[mini][w - 1].d > sumd[i][w - 1].d) mini = i;
    }
    cout << sumd[mini][w - 1].d << '\n';
    print_back(mini, w - 1);
}