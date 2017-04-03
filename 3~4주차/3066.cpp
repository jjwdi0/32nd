#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int T, N;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		v.clear();
		for(int i=0, x; i<N; i++) {
			scanf("%d", &x);
			auto it = lower_bound(v.begin(), v.end(), x);
			if(it == v.end()) v.push_back(x);
			else *it = x;
		}
		printf("%d\n", (int)v.size());
	}
}
