#include <stdio.h>
#include <queue>
using namespace std;

queue <int> q;
int A[100005], N, M;

void f() {
    while(!q.empty()) {
		if(a[m]) { printf("%d", A[M]); break; }
    	if(q.front() - 1 >= 0) {
			if(A[q.front()-1] == 0) {
				A[q.front()-1] = A[q.front()] + 1;
				q.push(q.front() - 1);
			}
		}
    	if(q.front() + 1 <= 100000) {
			if(A[q.front()+1] == 0) {
				A[q.front()+1] = A[q.front()] + 1;
    			q.push(q.front() + 1);
			}
		}
    	if(2 * q.front() <= 100000) {
			if(A[q.front()*2] == 0) {
				A[2*q.front()] = A[q.front()] + 1;
    			q.push(2 * q.front());
			}
		}
    	q.pop();
	}
}

int main() {
    scanf("%d %d", &N, &M);
    q.push(N);
    if(N == M) printf("0");
    else if(N > M) printf("%d", N - M);
    else f();
}
