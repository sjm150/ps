#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string name, act;
        cin >> name >> act;
        if (act == "enter") s.insert(name);
        else s.erase(name);
    }
    for (auto it = s.rbegin(); it != s.rend(); it++) cout << *it << '\n';
}