#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const string dow[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    const int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d, m;
    cin >> d >> m;
    int x = d - 1;
    for (int i = 1; i < m; i++) x += day[i - 1];
    cout << dow[x % 7] << '\n';
}