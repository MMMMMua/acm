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

void lca_init(int x, int f) {
	d[x] = d[lca[x][0] = f] + 1;
	for (int i = 1; i < 20; ++i) {
		lca[x][i] = lca[lca[x][i-1]][i-1];
		
	}
	for (int i = la[x]; i; i = nt[i])
		if (to[i] != f) lca_init(to[i], x);					   
}

int query(int x, int y) {
	if (d[x] < d[y]) swap(x, y);
	while 
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	gint(n), gint(m);

	for (int i = 1; i <= m; ++i)
		gint(u[i]), gint(v[i]), gint(w[i]), id[i] = i;

	sort(id+1, id+m+1, cmp);
	
	for (int i = 1; i <= n; ++i) ufs[i] = i;
	for (int i = 1; i <= m; ++i) {
		int x = id[i];
		if (find(u[x]) != find(v[x])) 
			ufs[u[x]] = ufs[v[x]], add_edge(u[x], v[x]);		
	}

	lca_init(1, 0);

	for (gint(q); q--; ) {
		int x, y;
		gint(x), gint(y);

		printf("%d\n", query(x, y));
	}
}
 
