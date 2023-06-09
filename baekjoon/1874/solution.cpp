#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_n, n = 1;
    cin >> max_n;
    stack<int> s;
    string output = "";

    for (int i = 0; i < max_n; i++) {
        int num;
        cin >> num;

        if (num >= n) {
            int diff = num - n;
            for (int j = 0; j < diff; j++) {
                s.push(n++);
                output += "+\n";
            }
            n++;
            output += "+\n-\n";
        } else {
            if (num != s.top()) {
                cout << "NO\n";
                return 0;
            } else {
                output += "-\n";
                s.pop();
            }
        }
    }

    cout << output;
}