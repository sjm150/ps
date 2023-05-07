#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> times) {
    int t = times.size();
    vector<double> inv(t);
    double sum_inv = 0.0;
    for (int i = 0; i < t; i++) {
        inv[i] = 1.0 / double(times[i]);
        sum_inv += inv[i];
    }

    long long min_time = INT64_MAX;
    int left = n;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 0; i < t; i++) {
        int load = n * inv[i] / sum_inv;
        left -= load;
        pq.emplace((long long)(load + 1) * times[i], i);
    }

    while (left > 1) {
        long long end = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        pq.emplace(end + times[idx], idx);
        left--;
    }

    return pq.top().first;
}