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
int a[35];

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
	freopen("a.out","w",stdout);
#endif
    for (scanf("%d", &T); T--; ) {
		scanf("%llu", &n);

		ld s = solve(0, 100000, n*n);
	    sz=30;
		
	    for (int i = 1; i <= sz; ++i)
		{  
			a[i]=(int)s;
			if (s - (int)s < 1e-20) {
				sz = i; break;
			}
            s=1.0/(s-(int)s);
		}

		
		for (int i = sz; i >= 1; --i) {
			ll up = a[i], dw = 1;			
			for (int j = i-1; j >= 1; --j) {
				ll tup = a[j] * up + dw;
				ll tdw = up;
				up = tup;
				dw = tdw;
			}
			if (dw <= 100000) {
				printf("%llu/%llu\n",up, dw);
				break;
			}
		}
	}  
}
