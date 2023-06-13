#include <iostream>
#include <deque>

using namespace std;

void parse(string& contents, deque<int>& q) {
    int num = 0;
    for (int i = 1; i < contents.size() - 1; i++) {
        char c = contents[i];
        if (c == ',') {
            q.push_back(num);
            num = 0;
        } else {
            num = 10 * num + (c - '0');
        }
    }
    if (num) q.push_back(num);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string funs, contents;
        cin >> funs >> n >> contents;

        deque<int> q;
        parse(contents, q);

        bool print = true;
        bool reversed = false;
        for (char f: funs) {
            if (f == 'R') {
                reversed = !reversed;
            } else {
                if (q.empty()) {
                    cout << "error\n";
                    print = false;
                    break;
                } else {
                    if (!reversed) q.pop_front();
                    else q.pop_back();
                }
            }
        }

        if (print) {
            if (!reversed) {
                cout << '[';
                for (auto it = q.begin(); it != q.end(); it++) {
                    if (it != q.begin()) cout << ',';
                    cout << *it;
                }
                cout << "]\n";
            } else {
                cout << '[';
                for (auto it = q.rbegin(); it != q.rend(); it++) {
                    if (it != q.rbegin()) cout << ',';
                    cout << *it;
                }
                cout << "]\n";
            }
        }
    }
}