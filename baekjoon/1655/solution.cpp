#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    priority_queue<int> lpq;
    priority_queue<int, vector<int>, greater<int>> rpq;
    while (n--) {
        int x; cin >> x;
        if (lpq.empty() || lpq.top() > x) lpq.push(x);
        else rpq.push(x);
        if (lpq.size() >= rpq.size() + 2) {
            rpq.push(lpq.top());
            lpq.pop();
        } else if (lpq.size() < rpq.size()) {
            lpq.push(rpq.top());
            rpq.pop();
        }
        cout << lpq.top() << '\n';
    }
}