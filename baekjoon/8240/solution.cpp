#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> ans;
    vector<int> stk;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        stk.push_back(i);
        sum += s[i] == 'b' ? 1 : -k;
        if (stk.size() > k + 1) sum -= s[stk[stk.size() - k - 2]] == 'b' ? 1 : -k;
        if (sum == 0) {
            ans.emplace_back(stk.end() - k - 1, stk.end());
            stk.resize(stk.size() - k - 1);
            for (int i = max(0, int(stk.size() - k - 1)); i < stk.size(); i++) sum += s[stk[i]] == 'b' ? 1 : -k;
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto &a: ans) {
        for (int a: a) cout << a + 1 << ' ';
        cout << '\n';
    }
}