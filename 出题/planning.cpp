#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 1.1e3;

int to[maxn], nxt[maxn], w[maxn], la[maxn];
int indeg[maxn], T[maxn], stk[maxn];
int n, m, edg, sz;

void add_edge(int x, int y, int b) {
	to[++edg] = y, nxt[edg] = la[x], w[edg] = b, la[x] = edg;
	indeg[y]++;
}

bool topsort() {
	static bool vis[maxn];
	
	for (int i = 1; i <= n; ++i)
		if (indeg[i] == 0)
			vis[i] = true, stk[++sz] = i;
		else
			vis[i] = false;
	
	while (sz) {
		int x = stk[sz--];
		for (int i = la[x]; i; i = nxt[i]) {
			int y = to[i];
			T[y] = max(T[y], T[x] + w[i]);
			if (--indeg[y] == 0)
				vis[y] = true, stk[++sz] = y;
		}			
	}
	
	for (int i = 1; i <= n; ++i)
		if (vis[i] == false)
			return false;
	return true;
}

int main() {
#ifdef LOCAL
	freopen("p.in", "r", stdin);
	freopen("p.out", "w", stdout);
#endif
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i)
			T[i] = indeg[i] = la[i] = 0;
		edg = 0;
		
		for (int i = 1; i <= m; ++i) {
			int I, J, B;
			cin >> I >> J >> B;
			if (B < 0)
				swap(I, J), B = -B;
			add_edge(I, J, B);
		}

		if (topsort() == false)
			printf("NO SOLUTION\n\n");
		else {
			for (int i = 1; i <= n; ++i)
				printf("%d\n", T[i]);
			printf("\n");
		}			
	}
							  
}
