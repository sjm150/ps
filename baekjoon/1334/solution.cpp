#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();

    int comp = 0;
    int i = n / 2;
    for (; i < n; i++) {
        char c = s[n - 1 - i];
        if (!comp) {
            if (c < s[i]) comp = -1;
            else if (c > s[i]) comp = 1;
        }
        s[i] = c;
    }

    if (comp > 0) {
        cout << s << '\n';
        return 0;
    }

    i = n / 2;
    for (; i < n; i++) {
        char &c = s[n - 1 - i];
        if (c < '9') {
            s[i] = ++c;
            break;
        }
        s[i] = c = '0';
    }

    if (i < n) {
        cout << s << '\n';
    } else {
        cout << '1';
        for (int i = 0; i < n - 1; i++) cout << '0';
        cout << "1\n";
    }
}