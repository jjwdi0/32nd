#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int test, N, M, color[20005];
vector<int> v[20005];

bool dfs(int x, int par) {
	if(color[par] == 1) color[x] = 2; else color[x] = 1;
	bool chk = false;
	for(int i=0; i<v[x].size(); i++) {
		if(color[v[x][i]] == color[x]) return true;
		if(!color[v[x][i]] && dfs(v[x][i], x)) return true;
	}
	return chk;
}

int main() {
	scanf("%d", &test);
	while(test--) {
		for(int i=0; i<=N; color[i]=0, i++) v[i].clear();
		bool deter = true;
		scanf("%d %d", &N, &M);
		while(M--) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			v[t1].push_back(t2);
			v[t2].push_back(t1);
		}
		for(int i=1; i<=N; i++) if(!color[i]) if(dfs(i, 0)) deter = false;
		puts(deter ? "YES" : "NO");
	}
}
