#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> last;
string no[500000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int k, l; cin >> k >> l;
    for (int i = 0; i < l; i++) {
        cin >> no[i];
        last[no[i]] = i;
    }
    for (int i = 0; i < l; i++) {
        if (k == 0) break;
        if (last[no[i]] == i) {
            cout << no[i] << '\n';
            k--;
        }
    }
}