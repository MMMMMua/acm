#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2500, maxm = 1e5+50;
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

int n, d;
int f[maxn][25];
int a[maxn], b[maxn];

int getCost(int l, int r) {
	int cst = b[r] - b[l];
	if (cst % 10 >= 5) return cst + (10 - cst % 10);
	else return cst - (cst % 10);
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    cin >> n >> d;
	d++;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], b[i] = b[i-1] + a[i];

	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 0, t; k < d; ++k)
				if (f[j][k+1] > (t = getCost(i, j) + f[i][k]))
					f[j][k+1] = t;

	int ans = inf;
	for (int i = 1; i <= d; ++i) ans = min(ans, f[n][i]);

	cout << ans << endl;
}
