#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> subs;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            string sub = s.substr(i, j + 1 - i);
            if (subs.find(sub) == subs.end()) {
                subs.insert(sub);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}