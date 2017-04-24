#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

// USACO - Milk Scheduling

struct data{ int x, y; } t[200005];
int par[200005], N, milk[200005];
bool cmp(const data &a, const data &b) { return a.x > b.x; }

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void uni(int x, int y) {
	x = find(x), y = find(y);
	if(x < y)par[y] = x;
	else par[x] = y;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d", &t[i].y, &t[i].x);
	for(int i=0; i<200005; i++) par[i] = i;
	sort(t, t+n, cmp);
	for(int i=0; i<N; i++) {
		if(find(t[i].y) == 0) continue;
		milk[find(t[i].y)] = t[i].x;
		uni(find(t[i].y), find(t[i].y) - 1);
	}
	ll cnt = 0;
	for(int i=0; i<200005; i++) cnt += (ll)milk[i];
	printf("%lld", cnt);
}
