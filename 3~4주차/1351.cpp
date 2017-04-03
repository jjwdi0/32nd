#include <stdio.h>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> m;
ll a, b, c;

ll f(ll x) {
	if(m.find(x) != m.end()) return m[x];
	if(x == 0LL) return m[x] = 1LL;
	return m[x] = f(x / b) + f(x / c);
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", f(a));
}
