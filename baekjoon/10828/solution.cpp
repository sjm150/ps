#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    stack<int> s;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (cmd == "pop") {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << s.size() << '\n';
        } else if (cmd == "empty") {
            if (s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            if (!s.empty()) cout << s.top() << '\n';
            else cout << -1 << '\n';
        }
    }
}