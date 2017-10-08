#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 5050, maxm = 1e5+50;
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

int T, m, cnt, w, kase;
map<pii, int> M;
int d[maxn][maxn], mp[maxn][maxn];
pii u, v;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    for (cin >> T; T--; ) {
		cin >> m;
		cnt = 0;
		M.clear();
		memset(d, 0x3f, sizeof(d));
		memset(mp, 0x3f, sizeof(mp));
		for (int i = 1; i <= m; ++i) {
			cin >> u.fi >> u.se >> v.fi >> v.se >> w;
			M[u] = M[u] == 0 ? ++cnt : M[u];
			M[v] = M[v] == 0 ? ++cnt : M[v];

			mp[M[u]][M[v]] = mp[M[v]][M[u]] =
				d[M[u]][M[v]] = d[M[v]][M[u]] = w;
		}

		int Ans = inf;
		for (int k = 1; k <= cnt; ++k) {
			for(int i=1;i<k;i++)  
                for(int j=i+1;j<k;j++)  
                    Ans = min(Ans,d[i][j]+mp[i][k]+mp[k][j]);//跟新k点之前枚举ij求经过ijk的最小环  
					
			for (int i = 1; i <= cnt; ++i)
				for (int j = 1; j <= cnt; ++j)
					if (i != j && j != k && k != i)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}

		printf("Case #%d: %d\n", ++kase, Ans);
	}
}

