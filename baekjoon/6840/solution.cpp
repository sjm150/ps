#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    for (int &a: a) cin >> a;
    sort(a, a + 3);
    cout << a[1] << '\n';
}