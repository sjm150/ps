#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto solve = [&]() {
        int cnt = 0;
        for (char c: s) cnt += c == 'H';
        if (cnt % 2) return false;
        cnt /= 2;
        if (cnt * 3 != n) return false;

        int h = 0, o = 0;
        for (char c: s) {
            (c == 'H' ? h : o)++;
            if (h < o) return false;
            if (cnt * 2 - h < cnt - o) return false;
        }
        return true;
    };

    cout << (solve() ? "pure\n" : "mix\n");
}