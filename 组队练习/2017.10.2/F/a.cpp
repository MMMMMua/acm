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

const int bSize = 245;
int n, k, bTot;
int Max[maxn], Min[maxn];
int A[maxn], B[maxn];
int Loc[maxn], Label[maxn];

int bisearch(int s, int t, int L, int R, int liml, int limr) {
	int l = liml-1, r = limr-1, mid, ret, cnt;

	while (l <= r) {
		mid = l + r >> 1;
		cnt = 0;
		for (int i = L+1; i < R; ++i) {
			
			int p = upper_bound(B+Min[i], B+Max[i]+1, mid - Label[i]) - B;
			int q = p - Min[i];
			cnt += q;
		}

		for (int i = s; Loc[i] == L && i <= t; ++i) cnt += (A[i] <= mid - Label[L]);
		if (L != R)
			for (int i = t; Loc[i] == R && i >= s; --i) cnt += (A[i] <= mid - Label[R]);
		
		if (cnt <= n/2) l = mid+1, ret = mid;
		else r = mid - 1;
	}
	return ret+1;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    while(~scanf("%d %d", &n, &k), n || k) {
		for (int i = 1; i <= n; ++i) gint(A[i]);

		for (int i = 1; i <= n; ++i)
			Loc[i] = i / bSize + 1, Max[i / bSize + 1] = i;
		for (int i = n; i >= 1; --i)
			Min[i / bSize + 1] = i;
		
		Loc[n+1] = 0;

		bTot = n/bSize + 1;
		for (int i = 1; i <= bTot; ++i) Label[i] = 0;

		int liml = 1, limr = 1e9+1, la;
		for (int i = 1; i <= bTot; ++i) {			
			memcpy(B+Min[i], A+Min[i], sizeof(int)*(Max[i] - Min[i]+1));
			sort(B+Min[i], B+Max[i]+1);
		}
		
		while (k--) {
			int s, t;
			gint(s), gint(t);
			int l = Loc[s], r = Loc[t];

			for (int i = l+1; i < r; ++i) Label[i]++;
			for (int i = s; Loc[i] == l && i <= t; ++i) A[i]++;
			if (l != r)
				for (int i = t; Loc[i] == r && i >= l; --i) A[i]++;

			memcpy(B+Min[l], A+Min[l], sizeof(int)*(Max[l] - Min[l]+1));
			memcpy(B+Min[r], A+Min[r], sizeof(int)*(Max[r] - Min[r]+1));

			sort(B+Min[l], B+Max[l]+1);
			sort(B+Min[r], B+Max[r]+1);

			printf("%d\n", la = bisearch(1, n, 1, bTot, liml, limr));
			liml = la, limr = la+1;
		}
	}
}
