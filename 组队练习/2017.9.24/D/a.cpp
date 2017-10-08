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

ld a, b;
ld f[30][30], d[30][30];
bool vis[30][30];
pii t[30][30];
int n, m;


ld dfs(int i, int j) {
	if (i == 1 && j == 1) return d[1][1];
	if (vis[i][j]) return f[i][j];
	if (i <= 0 || j <= 0) return inf;

	f[i][j] = inf;
	vis[i][j] = 1;

	ld A1 = dfs(i-2, j-1) + a * (d[i-1][j] + d[i][j]);
	ld A2 = dfs(i-1, j-1) + b * d[i][j];
	ld A3 = dfs(i-1, j-2) + a * (d[i][j-1] + d[i][j]);

	if (f[i][j] > A1)		
		f[i][j] = A1, t[i][j] = pii(i-2, j-1);
	if (f[i][j] > A2)
		f[i][j] = A2, t[i][j] = pii(i-1, j-1);
	if (f[i][j] > A3)
		f[i][j] = A3, t[i][j] = pii(i-1, j-2);

	return f[i][j];
}

void prt(int i, int j) {
	if (i != 1 && j != 1)
		prt(t[i][j].fi, t[i][j].se);
	if (t[i][j] == pii(i-2, j-1))
		printf("(%d,%d)\n",j,i-1);
	if (t[i][j] == pii(i-1, j-2))
		printf("(%d,%d)\n",j-1,i);	 
	printf("(%d,%d)\n",j,i);
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	cin >> a >> b;	
	while (~scanf("%lf",&d[++n][1])) {
		m = 1;
		while (getchar() != '\n') {
			scanf("%lf", &d[n][++m]);
		}
	}
	n--;

	printf("%.6lf\n",dfs(n, m));

	prt(n, m);
}
