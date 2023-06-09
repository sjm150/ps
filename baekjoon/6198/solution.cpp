#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    stack<int> s;
    int n;
    long long int sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        while (!s.empty() && s.top() <= h) s.pop();
        sum += s.size();
        s.push(h);
    }

    cout << sum << '\n';
}