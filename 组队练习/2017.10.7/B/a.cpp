#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <ll, int> pii;

const int maxn = 2e6+50, maxm = 1e5+50;
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

priority_queue<pii, vector<pii>, greater<pii> > q;
int T, n, m, L, kase;
ll tw[maxn], td[maxn];
ll w[maxn], d[maxn];

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    for (gint(T); T--; ) {
		gint(L), gint(n); gint(m);
		for (int i = 1; i <= n; ++i)
			gint(w[i]), q.push(pii(w[i], i));

		for (int i = 1; i <= L; ++i) {
			pii pr = q.top();
			tw[i] = pr.fi;
			q.pop();
			pr.fi += w[pr.se];
			q.push(pr);
		}

		while (q.size()) q.pop();
		
		for (int i = 1; i <= m; ++i)
			gint(d[i]), q.push(pii(d[i], i));
		
		for (int i = 1; i <= L; ++i) {
			pii pr = q.top();
			td[L-i+1] = pr.fi;
			q.pop();
			pr.fi += d[pr.se];
			q.push(pr);
		}

		while (q.size()) q.pop();

		ll ans = 0;
		for (int i = 1; i <= L; ++i) ans = max(ans, td[i] + tw[i]);

		printf("Case #%d: %lld\n", ++kase, ans);
	}
}
