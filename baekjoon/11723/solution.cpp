#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int m; cin >> m;
    unordered_set<int> uset;
    while (m--) {
        string cmd; cin >> cmd;
        if (cmd == "add") {
            int x; cin >> x;
            uset.insert(x);
        } else if (cmd == "remove") {
            int x; cin >> x;
            auto it = uset.find(x);
            if (it != uset.end()) uset.erase(it);
        } else if (cmd == "check") {
            int x; cin >> x;
            auto it = uset.find(x);
            if (it != uset.end()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (cmd == "toggle") {
            int x; cin >> x;
            auto it = uset.find(x);
            if (it != uset.end()) uset.erase(it);
            else uset.insert(x);
        } else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) uset.insert(i);
        } else {
            uset = unordered_set<int>();
        }
    }
}