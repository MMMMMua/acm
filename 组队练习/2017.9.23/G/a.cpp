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

int vis[101][101];

int outbound(int x, int y) {
	return x < 1 || x > y;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int n = 99, m = 99;
    for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j) {
			memset(vis, 0, sizeof(vis));

			int x = 1, y = 1, dx = 1, dy = 1;
			while (!outbound(x, i) || !outbound(y, j)) {
				if (!outbound(x, i) && !outbound(y, j))
					vis[x][y]++, x += dx, y += dy;
				else {
					if (outbound(x, i))
						dx = -dx, x += dx * 2;
					if (outbound(y, j))
						dy = -dy, y += dy * 2;
					vis[x][y]++;
				}				
			}

			int cnt = 0;
			for (int tx = 1; tx <= i; ++tx, puts(""))
				for (int ty = 1; ty <= j; ++ty) {					
					cnt += (vis[tx][ty] == 1);
					printf("%d",vis[tx][ty]);
				}

			printf("\n\ni:%d  j:%d  cnt:%d\n", i, j, cnt-1);
		}
			
}
 
