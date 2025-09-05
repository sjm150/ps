#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<int, string> eqn;
    for (int i = 0; i < 64; i++) {
        string op;
        for (int j = 0, r = i; j < 3; j++, r /= 4) {
            if (r % 4 == 0) op += '+';
            else if (r % 4 == 1) op += '-';
            else if (r % 4 == 2) op += '*';
            else op += '/';
        }
        assert(op.size() == 3);
        string e = string("4 ") + op[0] + string(" 4 ") + op[1] + string(" 4 ") + op[2] + string(" 4 = ");
        vector<int> num = {4, 4, 4, 4};
        int idx = 0;
        while (idx < int(op.size())) {
            if (op[idx] == '*') {
                num[idx] *= num[idx + 1];
                num.erase(num.begin() + idx + 1);
                op.erase(op.begin() + idx);
            } else if (op[idx] == '/') {
                num[idx] /= num[idx + 1];
                num.erase(num.begin() + idx + 1);
                op.erase(op.begin() + idx);
            } else {
                idx++;
            }
        }
        idx = 0;
        while (idx < int(op.size())) {
            if (op[idx] == '+') {
                num[idx] += num[idx + 1];
                num.erase(num.begin() + idx + 1);
                op.erase(op.begin() + idx);
            } else if (op[idx] == '-') {
                num[idx] -= num[idx + 1];
                num.erase(num.begin() + idx + 1);
                op.erase(op.begin() + idx);
            } else {
                idx++;
            }
        }
        e += to_string(num[0]);
        eqn[num[0]] = e;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto it = eqn.find(n);
        cout << (it != eqn.end() ? it->second : "no solution") << '\n';
    }
}