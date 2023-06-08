#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int hour, minute, time;
    cin >> hour >> minute >> time;
    
    minute += time;
    hour += minute / 60;
    minute = minute % 60;
    hour = hour % 24;

    cout << hour << ' ' << minute << '\n';
}