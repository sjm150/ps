#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<string> ss(3);
    for (auto &s: ss) cin >> s;
    auto prnt = [&](int i) {
        if (i % 15 == 0) cout << "FizzBuzz\n";
        else if (i % 3 == 0) cout << "Fizz\n";
        else if (i % 5 == 0) cout << "Buzz\n";
        else cout << i << '\n';
    };
    for (int i = 0; i < 3; i++) {
        if ('0' <= ss[i][0] && ss[i][0] <= '9') {
            prnt(stoi(ss[i]) + 3 - i);
            break;
        }
    }
}