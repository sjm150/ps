#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> digits;
int n, m;

string possible_number();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        string d;
        cin >> d >> n >> m;
        digits.clear();
        for (char c: d) digits.emplace_back(c - '0');
        sort(digits.begin(), digits.end());

        cout << possible_number() << endl;
    }
}

unordered_map<int, string> mod_map;

string possible_number() {
    mod_map.clear();
    queue<int> q;

    mod_map[0] = "";
    q.emplace(0);
    while (!q.empty()) {
        int curr_mod = q.front();
        string curr = mod_map[curr_mod];
        q.pop();

        for (int d: digits) {
            int next_mod = curr_mod * 10 + d;
            next_mod = next_mod % n + (next_mod >= n ? n : 0);
            string next = string(curr);
            next.push_back(d + '0');

            if (next_mod == n + m) {
                return next;
            } else if (mod_map.find(next_mod) == mod_map.end()) {
                mod_map[next_mod] = next;
                q.emplace(next_mod);
            }
        }
    }

    return "IMPOSSIBLE";
}