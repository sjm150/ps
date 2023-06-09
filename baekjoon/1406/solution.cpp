#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string buf;
    cin >> buf;

    list<char> l;
    for (char c: buf) l.push_back(c);
    auto it = l.end();

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (it != l.begin()) it = prev(it);
        } else if (cmd == 'D') {
            if (it != l.end()) it = next(it);
        } else if (cmd == 'B') {
            if (it != l.begin()) it = l.erase(prev(it));
        } else {
            char c;
            cin >> c;
            it = next(l.insert(it, c));
        }
    }

    for (auto it = l.begin(); it != l.end(); it++) cout << *it;
    cout << '\n';
}