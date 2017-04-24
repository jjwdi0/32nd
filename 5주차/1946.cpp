#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

int T, N;
pair<int, int> A[111111];
stack<int> s;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0, x, y; i<N; i++) scanf("%d %d", &x, &y), A[i].first = N + 1 - x, A[i].second = N + 1 - y;
		sort(A, A + N);
		for(int i=0; i<N; i++) {
			while(!s.empty() && s.top() < A[i].second) s.pop();
			s.push(A[i].second);
		}
		printf("%d\n", s.size());
		while(!s.empty()) s.pop();
	}
}
