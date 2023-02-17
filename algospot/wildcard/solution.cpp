#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string pattern;
string filename;

int match_cache[101][101];

bool match(size_t p_pos, size_t f_pos);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        vector<string> matches;
        cin >> pattern;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> filename;

            for (int j = 0; j <= pattern.length(); j++) {
                for (int k = 0; k <= filename.length(); k++) {
                    match_cache[j][k] = -1;
                }
            }

            if (match(0, 0)) matches.push_back(filename);
        }

        sort(matches.begin(), matches.end());

        for (auto str: matches) {
            cout << str << endl;
        }
    }
}

bool match(size_t p_pos, size_t f_pos) {
    int& cache = match_cache[p_pos][f_pos];
    if (cache >= 0) return cache == 1;

    if (f_pos == filename.length()) {
        if (p_pos == pattern.length() || (pattern[p_pos] == '*' && pattern.find_first_not_of('*', p_pos) == string::npos)) {
            cache = 1;
            return true;
        } else {
            cache = 0;
            return false;
        }
    }

    if (p_pos < pattern.length() && (pattern[p_pos] == '?' || pattern[p_pos] == filename[f_pos])) {
        cache = match(p_pos + 1, f_pos + 1) ? 1 : 0;
        return cache == 1;
    } else if (pattern[p_pos] == '*') {
        if (match(p_pos, f_pos + 1) || match(p_pos + 1, f_pos)) {
            cache = 1;
            return true;
        }
    }

    cache = 0;
    return false;
}