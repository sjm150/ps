#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    vector<int> seq;
    for (int a: a) {
        auto it = lower_bound(seq.begin(), seq.end(), a, greater<int>());
        if (it == seq.end()) seq.push_back(a);
        else *it = a;
    }
    cout << seq.size() << '\n';
}