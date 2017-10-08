#include <iostream>
#include <cstring>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 305, maxm = 1e5+50;
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

int n, m, p;
int mat[maxn][maxn];
int f[maxn][2][2], g[maxn][2];
int Sum[maxn][maxn];
int Min[maxn][maxn][maxn];

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d %d",&n, &m, &p)) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j){
				scanf("%d",&mat[i][j]);
				Sum[i][j] = Sum[i][j-1] + mat[i][j];
			}

		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) {
				Min[i][j][j] = mat[i][j];
				for (int k = j+1; k <= m; ++k) {
					Min[i][j][k] = min(Min[i][j][k-1], mat[i][k]);
				}
			}
		
		int ans = -inf;
		
		for (int i = 1; i <= m; ++i)
			for (int j = i; j <= m; ++j) {				
				if (i == 1 && j == m) {
						for (int k = 1; k <= n; ++k) memset(f[k], -0x3f, sizeof(f[k]));

						f[0][0][0] = f[0][1][1] = f[0][1][0] = -inf; //1 ding
						f[0][0][1] = 0;
					
						for (int k = 1; k <= n; ++k) {
							int A = Sum[k][j] - Sum[k][i-1], B = Sum[k][j] - Sum[k][i-1] - Min[k][i][j] + p;
							if (k != 1) {
								f[k][0][0] = max(f[k-1][0][0], 0) + A;							
								f[k][1][0] = max(max(f[k-1][0][0], 0) + B, f[k-1][1][0] + A);
							}
						
							f[k][0][1] = f[k-1][0][1] + A;
							f[k][1][1] = max(f[k-1][0][1] + B, f[k-1][1][1] + A);
						
							if (i != 1 || j != m || k != n)
								ans = max(ans, max(max(f[k][0][0], f[k][1][0]), max(f[k][0][1], f[k][1][1])));
							else
								ans = max(ans, max(max(f[k][0][0], f[k][1][0]), f[k][1][1]));
						}						
					}
					else 
					{
						for (int k = 1; k <= n; ++k) memset(g[k], -0x3f, sizeof(g[k]));

						g[0][0] = 0;
						g[0][1] = -inf;

						for (int k = 1; k <= n; ++k) {
							int A = Sum[k][j] - Sum[k][i-1], B = Sum[k][j] - Sum[k][i-1] - Min[k][i][j] + p;
							g[k][0] = max(g[k-1][0], 0) + A;
							g[k][1] = max(g[k-1][1] + A, max(g[k-1][0], 0) + B);
							ans = max(ans, max(g[k][0], g[k][1]));
						}						
					}
				}

		printf("%d\n", ans);
	}
}
 
