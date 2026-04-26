#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, d, a;
    cin >> k;
    cin.ignore();
    cin >> d;
    cin.ignore();
    cin >> a;
    cout << (k + a < d || d == 0 ? "hasu\n" : "gosu\n");
}