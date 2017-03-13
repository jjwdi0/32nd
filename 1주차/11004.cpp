#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	scanf("%d %d", &N, &K);
	vector<int> v(N);
	for(auto &i : v) scanf("%d", &i);
	nth_element(v.begin(), v.begin() + K - 1, v.end());
	printf("%d\n", v.at(K-1));
}
