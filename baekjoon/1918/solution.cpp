#include <bits/stdc++.h>
using namespace std;

int prior(char c) {
    if (c == '*' || c == '/') return 1;
    else return 0;
}

stack<char> ops;
stack<string> s;
void calc() {
    string b = s.top(); s.pop();
    string a = s.top(); s.pop();
    char op = ops.top(); ops.pop();
    s.push(a + b + op);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string eq; cin >> eq;
    for (char c: eq) {
        if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.top() != '(') calc();
            ops.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && ops.top() != '(' && prior(ops.top()) >= prior(c)) calc();
            ops.push(c);
        } else {
            s.push(string(1, c));
        }
    }
    while (!ops.empty()) calc();
    cout << s.top() << '\n';
}