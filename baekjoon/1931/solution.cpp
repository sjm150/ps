#include <iostream>
#include <algorithm>

using namespace std;

pair<uint, uint> conf[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        uint s, e;
        cin >> s >> e;
        conf[i] = {e, s};
    }
    sort(conf, conf + n);
    int num = 0;
    uint last = 0;
    for (int i = 0; i < n; i++) {
        if (conf[i].second >= last) {
            last = conf[i].first;
            num++;
        }
    }
    cout << num << '\n';
}