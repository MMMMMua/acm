#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef unsigned long long ll;
typedef long double ld;
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
int T, sz;
ll n;
int a[30];

ld solve(ld l, ld r, ll p) {
	ld mid;
	for (int i = 1; i <= 100; ++i) {
		mid = (l + r) / 2;
		ld t = mid*mid*mid;
		if (t <= p)
			l = mid;
		else
			r = mid;
	}
	return mid;
}
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	for (int i = 1; i <= 100000; ++i) {
		ld y = solve(1, 100000, (ll)i*i);
		ld dif, mindif = 1e100;
		ll ans, ret, dom;
		for (int p = 1; p <= 100000; ++p) {
			if (p == 96389) {
				int x;
				x++;
			}
			ld a = y - floor(y * (ld)p) / (ld)p;
			ld b = ceil(y * (ld)p)/ (ld)p - y;
			if (a < b)
				ans = (ll)floor(y*(ld)p), dif = a;
			else
				ans = (ll)ceil(y*(ld)p), dif = b;

			if (dif < mindif)
				mindif = dif, ret = ans, dom = p;
		}

		cout << ret << "/" << dom << endl;
									 cerr << i << endl;
	}
}
