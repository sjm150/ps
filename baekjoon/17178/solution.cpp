#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto get = [&]() {
        string s; cin >> s;
        return make_pair(s[0], stoi(s.substr(2)));
    };
    int n; cin >> n;
    n *= 5;
    stack<pair<char, int>> stk;
    auto lst = make_pair('A', 0);
    bool poss = true;
    while (n--) {
        auto cur = get();
        while (!stk.empty() && stk.top() < cur) {
            if (lst > stk.top()) poss = false;
            lst = stk.top();
            stk.pop();
        }
        stk.push(cur);
    }
    if (lst > stk.top()) poss = false;
    cout << (poss ? "GOOD\n" : "BAD\n");
}