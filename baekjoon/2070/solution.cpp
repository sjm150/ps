#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;

    auto chk = [&](int l, int r) {
        int len = r - l + 1;
        string cur = s.substr(l, len);
        for (int i = 1; i < len; i++) {
            if (cur > s.substr(l + i, len - i) + s.substr(l, i)) return false;
        }
        return true;
    };

    int n = s.size();
    for (int i = 0; i < n;) {
        int j = n - 1;
        while (i < j && !chk(i, j)) j--;
        cout << '(' << s.substr(i, j - i + 1) << ')';
        i = j + 1;
    }
    cout << '\n';
}