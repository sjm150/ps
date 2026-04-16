#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<string, double> mx = {{"pink", 0}};
    while (n--) {
        string o, w;
        double r;
        cin >> o >> w >> r;
        auto wit = mx.find(w);
        if (wit != mx.end()) {
            auto oit = mx.find(o);
            if (oit != mx.end()) oit->second = max(oit->second, wit->second + log(r));
            else mx[o] = wit->second + log(r);
        }
    }
    auto it = mx.find("blue");
    cout << setprecision(8) << fixed << (it != mx.end() ? exp(min(log(10.0), it->second)) : 0.0) << '\n';
}