#include <bits/stdc++.h>
using namespace std;

int k, n, x[1004], y[1004], m[1004][1004], re[1004][1004], r[1004];

int dist(int a, int b) { return abs(x[a] - x[b]) + abs(y[a] - y[b]); }

int dp(int p, int q) {
	if(p == n + 1 or q == n + 1) return 0;
	if(m[p][q]) return m[p][q];
	int nxt = max(p, q) + 1;
	int a = dp(nxt, q) + dist(p, nxt);
	int b = dp(p, nxt) + dist(q, nxt);
	if(a < b) m[p][q] = a, re[p][q] = 1;
	else m[p][q] = b, re[p][q] = 2;
	return m[p][q];
}

int main() {
	scanf("%d %d", &k, &n);
	x[0] = y[0] = 1;
	x[1] = y[1] = k;
	for (int i=0; i<n; i++) scanf("%d %d", x+i+2, y+i+2);
	printf("%d\n", dp(0, 1));
	int a = 0, b = 1;
	while (a < n + 1 and b < n + 1) {
		int nxt = max(a, b) + 1;
		if (re[a][b] == 1) r[nxt] = 1, a = nxt;
		else r[nxt] = 2, b = nxt;
	}
	for (int i=2; i<n+2; i++) printf("%d\n", r[i]);
}

