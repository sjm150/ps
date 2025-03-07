#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();

    vector<pair<int, int>> p;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            p.emplace_back(st.top(), i);
            st.pop();
        }
    }

    int sz = p.size();
    vector<bool> skip(n, false);
    set<string> ans;
    for (int i = 1; i < (1 << sz); i++) {
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) skip[p[j].first] = skip[p[j].second] = true;
        }
        string cur;
        for (int i = 0; i < n; i++) {
            if (!skip[i]) cur += s[i];
        }
        ans.insert(cur);
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) skip[p[j].first] = skip[p[j].second] = false;
        }
    }

    for (auto &a: ans) cout << a << '\n';
}