#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> tpi;
const int maxn = 60, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
typedef int arrn[maxn];
typedef ll arrm[maxn];

pii beg, fin;
int f[maxn][maxn][maxn];
tpi pre[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int cmr[maxn], cmc[maxn];
char str[maxn][maxn], cmd[maxn];
int n, m, len;
queue<tpi> q;

int spfa() {
	int ret = inf;
	memset(f, 0x3f, sizeof(f));
	f[0][beg.fi][beg.se] = 0;
	q.push({0, {beg.fi, beg.se}});

	while (q.size()) {
		tpi x = q.front(); q.pop();
		int l = x.fi, r = x.se.fi, c = x.se.se;
		vis[l][r][c] = 0;
		if (r == fin.fi && c == fin.se) {
			ret = min(ret, f[l][r][c]);
			continue;
		}
		
		if (l < len) {
			if (f[l+1][r][c] > f[l][r][c] + 1) {
				f[l+1][r][c] = f[l][r][c] + 1;
				pre[l+1][r][c] = {l, {r, c}};
				if (!vis[l+1][r][c])
					vis[l+1][r][c] = 1, q.push({l+1, {r, c}});
			}
			int tx = r + cmr[l+1], ty = c + cmc[l+1];
			if (str[tx][ty] == '#') tx = r, ty = c;
			if (f[l+1][tx][ty] > f[l][r][c]) {
				f[l+1][tx][ty] = f[l][r][c];
				pre[l+1][tx][ty] = {l, {r, c}};
				if (!vis[l+1][tx][ty])
					vis[l+1][tx][ty] = 1, q.push({l+1, {tx, ty}});
			}
		}
		for (int k = 0; k < 4; ++k) { //insert			
			int tx = r + dx[k], ty = c + dy[k];
			if (str[tx][ty] == '#')
				tx = r, ty = c;
			if (f[l][tx][ty] > f[l][r][c] + 1) {				
				f[l][tx][ty] = f[l][r][c] + 1;
				pre[l][tx][ty] = {l, {r, c}};
				if (!vis[l][tx][ty])
					vis[l][tx][ty] = 1, q.push({l, {tx, ty}});
			}
		}
				
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    cin >> n >> m;
	for (int i = 0; i <= n+1; ++i)
		for (int j = 0; j <= m+1; ++j)
			str[i][j] = '#';
										   
	for (int i = 1; i <= n; ++i)
		scanf("%s", str[i]+1), str[i][m+1] = '#';
	
	scanf("%s", cmd+1);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (str[i][j] != '#') {
				if (str[i][j] == 'R')
					beg = pii(i, j);
				if (str[i][j] == 'E')
					fin = pii(i, j);
			}


	len = strlen(cmd+1);
	for (int i = 1; i <= len; ++i) {
		cmr[i] = cmd[i] == 'U' ? -1 : (cmd[i] == 'D' ? 1 : 0);
		cmc[i] = cmd[i] == 'L' ? -1 : (cmd[i] == 'R' ? 1 : 0);
	}
	
	cout << spfa() << endl;
}
