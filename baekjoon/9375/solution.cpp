#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        unordered_map<string, int> kinds;
        int n; cin >> n;
        while (n--) {
            string name, kind;
            cin >> name >> kind;
            if (kinds.find(kind) != kinds.end()) kinds[kind]++;
            else kinds[kind] = 1;
        }
        int ans = 1;
        for (auto [k, v]: kinds) ans *= (v + 1);
        ans--;
        cout << ans << '\n';
    }
}