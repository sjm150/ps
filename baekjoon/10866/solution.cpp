#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    deque<int> q;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x;
            cin >> x;
            q.push_front(x);
        } else if (cmd == "push_back") {
            int x;
            cin >> x;
            q.push_back(x);
        } else if (cmd == "pop_front") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop_front();
            } else {
                cout << "-1\n";
            }
        } else if (cmd == "pop_back") {
            if (!q.empty()) {
                cout << q.back() << '\n';
                q.pop_back();
            } else {
                cout << "-1\n";
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << (q.empty()? 1 : 0) << '\n';
        } else if (cmd == "front") {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << "-1\n";
        } else {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << "-1\n";
        }
    }
}