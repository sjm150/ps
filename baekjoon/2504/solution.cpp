#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    stack<bool> s;
    int coef = 1, val = 0;
    bool opened = false;
    string ps;
    cin >> ps;

    for (char c: ps) {
        if (c == '(') {
            coef *= 2;
            s.push(false);
            opened = true;
        } else if (c == '[') {
            coef *= 3;
            s.push(true);
            opened = true;
        } else if (c == ')') {
            if (!s.empty() && (s.top() == false)) {
                if (opened) val += coef;
                coef /= 2;
                s.pop();
            } else {
                val = 0;
                break;
            }
            opened = false;
        } else {
            if (!s.empty() && (s.top() == true)) {
                if (opened) val += coef;
                coef /= 3;
                s.pop();
            } else {
                val = 0;
                break;
            }
            opened = false;
        }
    }

    if (!s.empty()) val = 0;
    cout << val << '\n';
}