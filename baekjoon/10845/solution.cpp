#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (cmd == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            } else {
                cout << "-1\n";
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << "-1\n";
        } else {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << "-1\n";
        }
    }
}