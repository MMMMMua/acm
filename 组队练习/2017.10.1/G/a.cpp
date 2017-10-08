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

int T, k;
ll n, m, sum;
ll Row[maxn], Col[maxn];
int p[25];

void dfs(int d, int s) {
	if (d == k + 1) {
		ll MinRow=n, MaxRow=1, MinCol = m, MaxCol = 1;
		for (int i = 1; i <= k; ++i)
			if (p[i] == 1) {
				MinRow = min(MinRow, Row[i]), MaxRow = max(MaxRow, Row[i]);
				MinCol = min(MinCol, Col[i]), MaxCol = max(MaxCol, Col[i]);				
			}
		sum += (ll)s * MinRow * MinCol * (n + 1 - MaxRow) * (m + 1 - MaxCol);
		return;
	}
	p[d] = 0;
	dfs(d+1, s);
	p[d] = 1;
	dfs(d+1, -s);
}
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

    for (gint(T); T--; ) {
		gint(n), gint(m), gint(k);
		for (int i = 1; i <= k; ++i)
			gint(Row[i]), gint(Col[i]);

		sum = 0;
		dfs(1, 1);
		sum -= n * m * n * m - (n*(n+1)/2) * (m*(m+1)/2);
		cout << sum << endl;
	}
}
 
