#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, w, h;
    cin >> n >> w >> h;
    int x = w * w + h * h;
    while (n--) {
        int a;
        cin >> a;
        cout << (a * a <= x ? "DA\n" : "NE\n");
    }
}