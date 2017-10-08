#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e6+50;
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

int n, d, l, m, dfn, edg;
arrn r, c, la;
arrm to, nt; 
int p[maxn][2];
bool vis[2020][2020];

void add_edge(int x, int y) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg;
}

void dfs(bool vis[], int x) {
	vis[x] = 1;
	for (int i = la[x]; i; i = nt[i])
		if (vis[to[i]] == 0)
			dfs(vis, to[i]);
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    cin >> n >> d >> l;
	for (int i = 1; i <= l; ++i) cin >> r[i] >> c[i];

	m = 1;
	for (int i = 1; i <= l; ++i)
		p[i][0] = ++m, p[i][1] = ++m;
	for (int i = 1; i <= l; ++i)
		for (int j = i+1; j <= l; ++j) {
			if ((abs(r[i] - r[j]) <= 2*d && c[i] == c[j]))
				add_edge(p[i][0], p[j][1]), add_edge(p[j][0], p[i][1]);
			
			if (abs(c[i] - c[j]) <= 2*d && r[i] == r[j])
				add_edge(p[i][1], p[j][0]), add_edge(p[j][1], p[i][0]);
		}

	for (int i = 2; i <= m; ++i)
		dfs(vis[i], i);
	for (int i = 1; i <= l; ++i)
			if (vis[p[i][0]][p[i][1]] && vis[p[i][1]][p[i][0]]) {
				puts("NO");
				exit(0);
			}				
	puts("YES");		
}

