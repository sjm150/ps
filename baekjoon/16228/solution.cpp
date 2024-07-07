#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;

    auto dgt = [&](char c) {
        return '0' <= c && c <= '9';
    };
    auto prio = [&](char c) {
        if (c == '+' || c == '-') return 0;
        else if (c == '<' || c == '>') return 1;
        else return 2;
    };
    auto eval = [&](int a, char op, int b) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '<') return min(a, b);
        else return max(a, b);
    };

    int idx = 0;
    stack<int> opnd;
    stack<char> opr;
    opr.push('(');
    s += ')';
    while (idx < s.size()) {
        if (s[idx] == '?') {
            idx++;
        } else if (dgt(s[idx])) {
            int x = 0;
            while (dgt(s[idx])) x = x * 10 + s[idx++] - '0';
            opnd.push(x);
        } else if (s[idx] == ')') {
            while (opr.top() != '(') {
                int b = opnd.top(); opnd.pop();
                opnd.top() = eval(opnd.top(), opr.top(), b);
                opr.pop();
            }
            opr.pop();
            idx++;
        } else {
            while (!opr.empty() && opr.top() != '(' && prio(opr.top()) >= prio(s[idx])) {
                int b = opnd.top(); opnd.pop();
                opnd.top() = eval(opnd.top(), opr.top(), b);
                opr.pop();
            }
            opr.push(s[idx++]);
        }
    }

    cout << opnd.top() << '\n';
}