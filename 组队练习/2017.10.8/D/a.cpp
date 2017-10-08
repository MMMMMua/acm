/#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <ll, int> pii;

const int maxn = 4e5+50, maxm = 1e5+50;
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

int T, n, kase, k;
ll b[maxn];
multiset<pii, greater<pii> > q;
multiset<pii, greater<pii> >::iterator it;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    for (gint(T); T--; ) {
		gint(n), gint(k);

		for (int i = 1; i <= n; ++i) gint(b[i]);
		if (k == 1) {
			printf("Case #%d: %d\n", ++kase, 1);
			continue;
		}
		
		sort(b+1, b+n+1);
		int l = 1, r = n, mid, cnt;
		while (l <= r) {
			mid = l + r >> 1;
			q.clear();
			for (int i = 1; i <= mid; ++i) q.insert(pii(b[i], 1));
			int tot = 0;
			for (int i = mid+1; i <= n && q.size(); ++i) {
				it = q.lower_bound(pii(b[i]/2, inf));
				if (it != q.end()) {
					pii tmp = *it;
					q.erase(it);
					if (tmp.se+1 != k)
						q.insert({b[i], tmp.se+1});
					else
						tot++;
				}
			}
			if (tot == mid) cnt = mid, l = mid+1;
			else r = mid-1;
		}
		
		printf("Case #%d: %d\n", ++kase, cnt);
	}
}

