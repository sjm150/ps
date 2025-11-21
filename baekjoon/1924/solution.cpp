#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const string dow[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    const int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x, y;
    cin >> x >> y;
    int d = y - 1;
    for (int i = 1; i < x; i++) d += day[i - 1];
    cout << dow[d % 7] << '\n';
}