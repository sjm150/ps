#include <bits/stdc++.h>
#include "island.h"
using namespace std;

void solve(int n, int l) {
	vector<int> dst(n + 1, 0), ord(n - 1), p(n + 1, -1);
	for (int i = 1; i < n; i++) {
		ord[i - 1] = query(1, i);
		dst[ord[i - 1]] = i;
	}
	for (int v: ord) {
		if (p[v] > 0) continue;
		for (int i = 1; i < n; i++) {
			int u = query(v, i);
			if (dst[u] < dst[v]) {
				p[v] = u;
				break;
			} else {
				p[u] = v;
			}
		}
	}
	for (int i = 2; i <= n; i++) answer(p[i], i);
}