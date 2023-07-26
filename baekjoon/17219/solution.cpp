#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> um;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (n--) {
        string url, pswd;
        cin >> url >> pswd;
        um[url] = pswd;
    }
    while (m--) {
        string url; cin >> url;
        cout << um[url] << '\n';
    }
}