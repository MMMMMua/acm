#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int edg, msz, n, m, T;
arrn id, nt, to, la, mk, a, maxd, d;

void add_edge(int x, int y) {
	to[++edg] = x, nt[edg] = la[x], la[x] = edg;
	to[++edg] = y, nt[edg] = la[y], la[y] = edg;
}

void init() {
	edg = 0;
	for (int i = 1; i <= n; ++i) la[i] = 0;
	msz = 0;
}

void dfs(int x, int f) {
	for (int i = la[x]; i; i = nt[i])
		if (to[i] != f) {
			d[to[i]] = d[x] + 1;
			dfs(to[i], x);
		}	
}

bool mark(int x, int t, int f) {
	if (x == t)
		return id[++msz] = t, mk[x] = 1, true;
		
	for (int i = la[x]; i; i = to[i])
		if (to[i] != f)
			if (dfs(to[i], t, x))
				return id[++msz] = x, mk[x] = 1, true;
	return false;
}

int getdep(int x, int f) {
	int ret = -1;
	for (int i = la[x]; i; i = to[i])
		if (to[i] != f)
			ret = max(ret, getdep(to[i], x));

	return ret;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (gint(T); T--; ) {
		gint(n);
		init();
		for (int i = 1, u, v; i < n; ++i)
			gint(u), gint(v), add_edge(u, v);

	    fill(d+1, d+n+1, 0);
		dfs(1, 0);

		int l = max_element(d+1, d+n+1) - d;
		fill(d+1, d+n+1, 0);

		dfs(l, 0);

		int r = max_element(d+1, d+n+1) - d;

		mark(l, r, 0);

		for (int i = 1; i <= n; ++i)
			if (mk[i] == 1)
				maxd[i] = getdep(i, 0);

		for (int i = 1; i <= msz; ++i)
			a[i] = maxd[id[i]];

		for (int i = 1; i <= msz; ++i)
			for (int j = i; j <= msz; ++j) {
				
			}
		
	}
}
 
