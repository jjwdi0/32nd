#include <bits/stdc++.h>
using namespace std;

int N;
struct data{ char name[13]; int g, e, m; } T[100005];

bool cmp(const data &a, const data &b) {
	if(a.g == b.g) {
		if(a.e == b.e) {
			if(a.m == b.m) {
				string x = "", y = "";
				for(int i=0; i<strlen(a.name); i++) x = x + a.name[i];
				for(int i=0; i<strlen(b.name); i++) y = y + b.name[i];
				return x < y;
			}
			return a.m > b.m;
		}
		return a.e < b.e;
	}
	return a.g > b.g;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s %d %d %d", &T[i].name, &T[i].g, &T[i].e, &T[i].m);
	sort(T, T+N, cmp);
	for(int i=0; i<N; i++) puts(T[i].name);
}
