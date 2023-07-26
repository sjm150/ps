#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> uset;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s, e, q;
    cin >> s >> e >> q;
    int status = 0;
    int cnt = 0;
    while (!cin.eof()) {
        string t, name;
        cin >> t >> name;
        if (status == 0) {
            if (t <= s) uset.insert(name);
            else status++;
        }
        if (status == 1) {
            if (t >= e) status++;
        }
        if (status == 2) {
            if (t <= q) {
                auto it = uset.find(name);
                if (it != uset.end()) {
                    uset.erase(it);
                    cnt++;
                }
            } else {
                status++;
            }
        }
    }
    cout << cnt << '\n';
}