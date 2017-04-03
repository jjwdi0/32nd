#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int N, A[10003], D[10003][2], par[10003];
vector<int> v[10005];

void dfs(int x, int y) {
	par[x] = y;
	for(auto it : v[x]) {
		if(it == par[x]) continue;
		dfs(it, x);
	}
}

int f(int x, bool state) {
	if(D[x][state]) return D[x][state];
	for(auto it : v[x]) {
		if(it == par[x]) continue;
		if(state) D[x][state] += f(it, !state);
		else D[x][state] += max(f(it, state), f(it, !state));
	}
	return D[x][state] = D[x][state] + A[x] * state;
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", A+i);
	for(int i=1, x, y; i<N; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1, 0);
	printf("%d", max(f(1, 0), f(1, 1)));
}