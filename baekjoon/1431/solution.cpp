#include <iostream>
#include <algorithm>

using namespace std;

struct Serial { string number; int sum; };
int n;
Serial serials[50];

bool cmp(Serial& a, Serial& b) {
    if (a.number.length() == b.number.length()) {
        if (a.sum == b.sum) return a.number < b.number;
        return a.sum < b.sum;
    }
    return a.number.length() < b.number.length();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        int sum = 0;
        for (char c: line) {
            if ('0' <= c && c <= '9')
                sum += c - '0';
        }
        serials[i] = Serial {line, sum};
    }
    sort(serials, serials + n, cmp);
    for (int i = 0; i < n; i++) cout << serials[i].number << '\n';
}