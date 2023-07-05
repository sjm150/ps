#include <iostream>
#include <algorithm>

using namespace std;

struct Member { int age; string name; };
Member members[100000];

bool cmp(const Member& a, const Member& b) {
    return a.age < b.age;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        members[i] = Member {age, name};
    }
    stable_sort(members, members + n, cmp);
    for (int i = 0; i < n; i++) cout << members[i].age << ' ' << members[i].name << '\n';
}