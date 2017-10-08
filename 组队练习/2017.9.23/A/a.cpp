#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> tpi;

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

int p[110], v[110];
int n, m, q;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
    while (~scanf("%d %d", &n, &m)) {
		for (int i = 1; i <= n; ++i)
			gint(p[i]), v[i] = 0;
		gint(q);
		for (int i = 1, j; i <= q; ++i)
			gint(j), v[j+1] = 1;

		for (int i = 1; i <= n; ++i)
			v[i] += v[i-1];


		tpi ans = tpi(inf, pii(0, 0));
		
		for (int i = 1; i <= n; ++i)
			for (int j = i+m-1; j <= n; ++j)
				if (v[i] == v[i-1] && v[j] - v[i-1] == j-i+1 - m)
					for (int k = i+1; k <= j; ++k)
						if (v[k] == v[k-1])
							ans = min(ans, tpi(p[i] + p[k], pii(i, k)));
					
		cout << ans.se.fi-1 << " " << ans.se.se-1 << endl;		
	}		  
}
