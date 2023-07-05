#include <iostream>
#include <algorithm>

using namespace std;

struct Point { int x; int y; };
Point points[100000];

bool cmp(Point& a, Point& b) {
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point {x, y};
    }
    sort(points, points + n, cmp);
    for (int i = 0; i < n; i++) cout << points[i].x << ' ' << points[i].y << '\n';
}