#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
typedef pair<int, pair<int, int>> tr;

int dp[103][10005], n, m, k;
vector<tr> v[105];
priority_queue<tr, vector<tr>, greater<tr>> q;

int main() {
	scanf("%d %d %d", &k, &n, &m);
	for(int i=0, x, y, z, w; i<m; i++) {
		scanf("%d %d %d %d", &x, &y, &z, &w);
		v[x].push_back({y, {w, z}});
	}
	for(int i=0; i<103; i++) for(int j=0; j<10005; j++) dp[i][j] = INF;
	q.push({0, {0, 1}});
	while(!q.empty()) {
		pair<int, pair<int, int>> T = q.top(); q.pop();
		if(dp[T.second.second][T.second.first] < T.first) continue;
		if(T.second.second == n) continue;
		for(auto i : v[temp.second.second]) {
			if(T.second.first + i.second.first > k) continue;
			if(dp[i.first][T.second.first + i.second.first] <= T.first + i.second.second) continue;
			q.push({T.first + i.second.second, {T.second.first + i.second.first, i.first}});
			dp[i.first][T.second.first + i.second.first] = i.second.second + T.first;
		}
	}
	int ans = INF;
	for(int i=0; i<=k; i++) ans = min(ans, dp[n][i]);
	printf("%d", ans == INF ? -1 : ans);
}
