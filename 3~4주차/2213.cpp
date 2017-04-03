#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_V 10005
using namespace std;

int V, C[MAX_V], P[MAX_V], D[MAX_V][2];
vector<int> adj[MAX_V], output;
vector<pair<int, int>> ans[MAX_V][2];
queue<pair<int, int>> Q;

int dp(int x, int state) {
	if(D[x][state]) return D[x][state];
	if(state) D[x][state] += C[x];
	for(auto it : adj[x]) {
		if(it == P[x]) continue;
		if(!state) {
			int C1 = dp(it, 0), C2 = dp(it, 1);
			ans[x][state].push_back({it, C1 < C2});
			D[x][state] += max(C1, C2);
		}
		else ans[x][state].push_back({it, 0}), D[x][state] += dp(it, 0);
	}
	return D[x][state];
}

int main() {
	scanf("%d", &V);
	for(int i = 1; i <= V; i++) scanf("%d", C + i);
	for(int i = 1, x, y; i < V; i++) scanf("%d %d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
	Q.push({1, 0});
	while(!Q.empty()) {
		int u = Q.front().first, v = Q.front().second; Q.pop();
		P[u] = v;
		for(auto it : adj[u]) {
			if(it == v) continue;
			Q.push({it, u});
		}
	}
	printf("%d\n", max(dp(1, 0), dp(1, 1)));
	Q.push({1, D[1][0] < D[1][1]});
	while(!Q.empty()) {
		int u = Q.front().first, state = Q.front().second; Q.pop();
		if(state) output.push_back(u);
		for(auto it : ans[u][state]) Q.push(it);
	}
	sort(output.begin(), output.end());
	for(auto it : output) printf("%d ", it);
}
