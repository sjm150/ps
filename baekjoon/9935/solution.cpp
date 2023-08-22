#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

string s, p;
vector<bool> del;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> s >> p;
    del = vector<bool>(s.size(), false);
    stack<pi> stk;
    int i = 0, j = 0;
    while (i < s.size()) {
        if (s[i] == p[j]) {
            stk.emplace(i, j);
            i++, j++;
            if (j == p.size()) {
                for (int k = 0; k < p.size(); k++) {
                    del[stk.top().first] = true;
                    stk.pop();
                }
                if (!stk.empty()) j = stk.top().second + 1;
                else j = 0;
            }
        } else {
            if (j == 0) {
                i++;
                if (!stk.empty()) stk = stack<pi>();
            } else {
                j = 0;
            }
        }
    }
    bool empty = true;
    for (int i = 0; i < s.size(); i++) {
        if (!del[i]) {
            cout << s[i];
            empty = false;
        }
    }
    if (empty) cout << "FRULA";
    cout << '\n';
}