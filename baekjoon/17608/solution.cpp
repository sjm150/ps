#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    stack<int> stk;
    while (n--) {
        int h;
        cin >> h;
        while (!stk.empty() && stk.top() <= h) stk.pop();
        stk.push(h);
    }
    cout << stk.size() << '\n';
}