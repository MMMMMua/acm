#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 1e-12, pi = acos(-1);
const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}
int m, L, U, D, R, x, y;
int a[1010][1010], bit[1010][1010];
char op[10];

void ins(int *bit, int p, int v) {
	for (int i = p; i <= 1001; i += lowbit(i)) bit[i] += v;	
}
int qer(int *bit, int p, int ret = 0) {
	for (; p; p -= lowbit(p)) ret += bit[p];
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d",&m);
	
	for (int i = 1; i <= m; ++i) {
		scanf("%s", op);
		if (op[0] == 'B' || op[0] == 'D') {
			scanf("%d %d", &x, &y);
			
			if (a[x][y] == (op[0] == 'B')) continue;
			
			a[x][y] = (op[0] == 'B');
			ins(bit[x+1], y+1, 1 - (op[0] != 'B')*2);
		}
		else {
			int ans = 0;
			scanf("%d %d %d %d", &U, &D, &L, &R);
			for (int i = min(U, D) + 1; i <= max(U, D) + 1; ++i)
				ans += qer(bit[i], max(L, R) + 1) - qer(bit[i], min(L, R));

			cout << ans << endl;
		}
	}
}
 
