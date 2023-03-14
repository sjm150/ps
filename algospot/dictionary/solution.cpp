#include <iostream>
#include <algorithm>

using namespace std;

bool edge[26][26];
void init_edge() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            edge[i][j] = false;
        }
    }
}

int n;

void build_dictionary();
string dictionary_to_string();
void order_dfs(int curr, string& order, bool (&visited)[26]);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n;
        init_edge();
        build_dictionary();
        cout << dictionary_to_string() << endl;
    }
}

void build_dictionary() {
    string prev;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < min(prev.length(), temp.length()); j++) {
            if (prev[j] != temp[j]) {
                edge[prev[j] - 'a'][temp[j] - 'a'] = true;
                break;
            }
        }

        prev = temp;
    }
}

string dictionary_to_string() {
    string order;
    bool visited[26];
    for (int i = 0; i < 26; i++) visited[i] = false;

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) order_dfs(i, order, visited);
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (edge[order[i] - 'a'][order[j] - 'a']) return "INVALID HYPOTHESIS";
        }
    }

    reverse(order.begin(), order.end());
    return order;
}

void order_dfs(int curr, string& order, bool (&visited)[26]) {
    visited[curr] = true;

    for (int next = 0; next < 26; next++) {
        if (edge[curr][next] && !visited[next]) {
            order_dfs(next, order, visited);
        }
    }

    order.push_back('a' + curr);
}