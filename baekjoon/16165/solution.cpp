#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, string> team;
unordered_map<string, vector<string>> members;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (n--) {
        string teamname;
        int num;
        cin >> teamname >> num;
        vector<string> mem(num);
        for (int i = 0; i < num; i++) {
            cin >> mem[i];
            team[mem[i]] = teamname;
        }
        sort(mem.begin(), mem.end());
        members[teamname] = mem;
    }
    while (m--) {
        string name;
        int type;
        cin >> name >> type;
        if (type == 0) {
            for (string& s: members[name]) cout << s << '\n';
        } else {
            cout << team[name] << '\n';
        }
    }
}