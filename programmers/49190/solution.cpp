#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int move(map<pair<int, int>, set<pair<int, int>>>& edges, const pair<int, int>& curr, const pair<int, int>& next) {
    auto it = edges.find(next);
    if (it == edges.end()) {
        edges.emplace(next, set<pair<int, int>>());
        edges[curr].insert(next);
        edges[next].insert(curr);
    } else if (edges[curr].find(next) == edges[curr].end()) {
        edges[curr].insert(next);
        edges[next].insert(curr);
        return 1;
    }
    return 0;
}

int solution(vector<int> arrows) {
    map<pair<int, int>, set<pair<int, int>>> edges;
    pair<int, int> curr = pair(0, 0);
    edges.emplace(curr, set<pair<int, int>>());

    int room = 0;
    for (int a: arrows) {
        if (a % 2 == 0) {
            pair<int, int> next = pair(curr.first + 2 * dx[a], curr.second + 2 * dy[a]);
            room += move(edges, curr, next);
            curr = next;
        } else {
            pair<int, int> next1 = pair(curr.first + dx[a], curr.second + dy[a]);
            pair<int, int> next2 = pair(next1.first + dx[a], next1.second + dy[a]);
            room += move(edges, curr, next1);
            room += move(edges, next1, next2);
            curr = next2;
        }
    }

    return room;
}