#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 250, maxm = 1e4+50;
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

int T, n, m, k, kase;
arrn t, c, p, x, y, vis;

int f[maxm];
int u[maxn][maxn], v[maxn][maxn], has[maxn][maxn];

queue<int> q;

void getPrice() {
	for (int i = 1; i <= m; ++i)
		if (c[i] < inf) q.push(i);
	while (q.size()) {
		int now = q.front(); q.pop();
		vis[now] = 0;
		for (int i = 1; i <= k; ++i)
			if (has[i][now]) {
				int cost = 0;
				for (int j = 1; j <= y[i]; ++j) {
					if (c[u[i][j]] == inf || cost > n) {
						cost = inf;
						break;
					}
					cost += c[u[i][j]] * v[i][j];
				}

				if (c[x[i]] > cost) {
					c[x[i]] = cost;
					if (!vis[x[i]])
						vis[x[i]] = 1, q.push(x[i]);
				}
			}
	}
}

int knapSack() {
	for (int i = 0; i <= n; ++i) f[i] = 0;
	
	for (int i = 1; i <= m; ++i)
		for (int j = c[i]; j <= n; ++j)
			f[j] = max(f[j], f[j-c[i]] + p[i]);
	return *max_element(f, f+n+1);
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    for (gint(T); T--; ) {
		scanf("%d %d %d", &n, &m, &k);

		for (int i = 1; i <= m; ++i) {
			scanf("%d", &t[i]);
			if (t[i] == 0) scanf("%d", &p[i]), c[i] = inf;
			else scanf("%d %d", &c[i], &p[i]);
		}

		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= m; ++j) has[i][j] = 0;
		
		for (int i = 1; i <= k; ++i) {
			scanf("%d %d", &x[i], &y[i]);
			for (int j = 1; j <= y[i]; ++j) {
				scanf("%d %d", &u[i][j], &v[i][j]); 
				has[i][u[i][j]] = 1;
			}
		}

		getPrice();

		printf("Case #%d: %d\n", ++kase, knapSack());
	}
}
 
