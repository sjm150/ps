#include <iostream>
#include <set>
typedef long long lint;
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        multiset<int> s;
        while (n--) {
            char c; int num;
            cin >> c >> num;
            if (c == 'I') {
                s.insert(num);
            } else {
                if (!s.empty()) {
                    if (num < 0) s.erase(s.begin());
                    else s.erase(prev(s.end()));
                }
            }
        }
        if (s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
}