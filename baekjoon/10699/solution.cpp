#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto t = chrono::system_clock::to_time_t(chrono::system_clock::now() + chrono::hours(9));
    auto tm = localtime(&t);
    tm->tm_hour += 9;
    char buf[12];
    strftime(buf, sizeof(buf), "%Y-%m-%d\n", tm);
    cout << buf;
}