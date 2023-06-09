#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k;
    cin >> k;

    stack<int> s;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            sum -= s.top();
            s.pop();
        } else {
            sum += num;
            s.push(num);
        }
    }

    cout << sum << '\n';
}