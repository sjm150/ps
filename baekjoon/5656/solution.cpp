#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int tc = 1;; tc++) {
        int a, b;
        string op;
        cin >> a >> op >> b;
        bool ok = false;
        if (op == ">") ok = a > b;
        else if (op == ">=") ok = a >= b;
        else if (op == "<") ok = a < b;
        else if (op == "<=") ok = a <= b;
        else if (op == "==") ok = a == b;
        else if (op == "!=") ok = a != b;
        else break;
        cout << "Case " << tc << ": " << (ok ? "true\n" : "false\n");
    }
}