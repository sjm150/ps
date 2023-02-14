#include <iostream>
#include <string>
#include <unordered_map>

std::string int_to_str[100000];

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, m;
    std::cin >> n >> m;

    std::string name;
    std::unordered_map<std::string, int> str_to_int;
    for (int i = 0; i < n ; i++) {
        std::cin >> name;

        str_to_int.insert(std::make_pair(name, i+1));
        int_to_str[i] = name;
    }

    std::string out = "";
    std::string buf;
    for (int i = 0; i < m; i++) {
        std::cin >> buf;

        auto iter = str_to_int.find(buf);
        if (iter == str_to_int.end()) {
            out += int_to_str[stoi(buf) - 1] + '\n';
        } else {
            out += std::to_string(iter->second) + '\n';
        }
    }

    std::cout << out;
}