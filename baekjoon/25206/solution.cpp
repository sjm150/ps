#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<string, double> scores;
    scores["A+"] = 4.5;
    scores["A0"] = 4.0;
    scores["B+"] = 3.5;
    scores["B0"] = 3.0;
    scores["C+"] = 2.5;
    scores["C0"] = 2.0;
    scores["D+"] = 1.5;
    scores["D0"] = 1.0;
    scores["F"] = 0.0;
    double totc = 0, sum = 0;
    for (int i = 0; i < 20; i++) {
        string s, g;
        double c;
        cin >> s >> c >> g;
        if (g == "P") continue;
        totc += c;
        sum += scores[g] * c;
    }
    cout << fixed << setprecision(6) << sum / totc << '\n';
}