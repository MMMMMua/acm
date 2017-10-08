#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> tpi;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n;
int a[4][maxn];
int p[maxn];
pii ptr[maxn];
tpi e[maxn];
int bit[maxn];

void init() {
	for (int i = 1; i <= n; ++i) p[a[1][i]] = i;
	for (int j = 1; j <= n; ++j) {
		for (int i = 2; i <= 3; ++i) a[i][j] = p[a[i][j]];
		ptr[a[2][j]].fi = j;
		ptr[a[3][j]].se = j;
	}
	// sort(ptr+1, ptr+n+1);
}

void prepare(int l, int m, int r) {
	for (int i = l; i <= m; ++i)
		e[i-l+1] = tpi(pii(ptr[i].fi, 1), ptr[i].se); //qer
	for (int i = m+1; i <= r; ++i)
		e[i-l+1] = tpi(pii(ptr[i].fi, -1), ptr[i].se); //mod

	sort(e+1, e+(r-l+1)+1);
}

int lowbit(int x) {
	return x & -x;
}

void ins(int p, int d) {
	for (int i = p; i <= n; i += lowbit(i))
		bit[i] += d;	
}

int qer(int p, int ret = 0) {
	for (; p; p -= lowbit(p))
		ret += bit[p];
	return ret;
}

ll scanline(int l, int r) {
	ll ret = 0;
	int cnt = 0;
	for (int i = r-l+1; i >= 1; --i)
		if (e[i].fi.se == -1) {
			assert(e[i].se > 0);
			ins(e[i].se, 1), cnt++;
		}
		else
			ret += cnt - qer(e[i].se);
	
	for (int i = 1; i <= r-l+1; ++i)
		if (e[i].fi.se == -1)
			ins(e[i].se, -1);
	
	return ret;
}

ll merge(int l, int r) {
	if (l == r) return 0;
	int mid = l + r >> 1;
	ll lans = merge(l, mid), rans = merge(mid+1, r);

	prepare(l, mid, r);
	ll cans = scanline(l, r);

	return lans + rans + cans;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    gint(n);
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= n; ++j)
			gint(a[i][j]);

	init();

	cout << merge(1, n) << endl;
}

