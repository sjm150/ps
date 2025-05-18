#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    auto resp = []() {
        int r;
        cin >> r;
        return r;
    };
    auto add = [&](ll y) {
        cout << "add " << y << endl;
        return resp();
    };
    auto mul = [&](ll y) {
        cout << "mul " << y << endl;
        return resp();
    };
    auto div = [&](ll y) {
        cout << "div " << y << endl;
        return resp();
    };
    auto digit = [&]() {
        cout << "digit" << endl;
        return resp();
    };
    auto submit = [&]() {
        cout << '!' << endl;
        int r = resp();
        assert(r == 1);
        return r;
    };

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        mul(9);
        digit();
        digit();
        add(n - 9);
        submit();
    }
}