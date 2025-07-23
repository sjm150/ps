#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a[6], b[6];
    for (int &a: a) cin >> a;
    for (int &b: b) cin >> b;
    auto scr = [](int a[]) {
        const int c[] = {13, 7, 5, 3, 3, 2};
        int s = 0;
        for (int i = 0; i < 6; i++) s += a[i] * c[i];
        return s;
    };
    cout << (scr(a) > scr(b) + 1 ? "cocjr0208\n" : "ekwoo\n");
}