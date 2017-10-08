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

struct Tri {
	int up, dn, dup, ddn, st, ed;
}tri[250];

pii e[maxn];
int eSize, n, m;
ll ans;


int main(){
	freopen("j.in","r",stdin);
    gint(n);
	gint(m);
	for (int i = 1; i <= m; ++i) {
		int row, col, l, d;
		gint(row), gint(col), gint(l), gint(d);
		switch(d) {
			case 0: col--; break;
			case 2: row--; break;
			case 3: col--, row--; break;
		}

		switch(d) {
			case 0: tri[i] = {row, row, 0, 1, col-l+1, col}; break;
			case 1: tri[i] = {row, row+l-1, 0, -1, col, col+l-1}; break;
			case 2: tri[i] = {row-l+1, row, 1, 0, col, col+l-1}; break;				
			case 3: tri[i] = {row, row, -1, 0, col-l+1, col}; break;
		}		
	}

	for (int i = -2*n-10; i <= 2*n+10; ++i) {
		eSize = 0;
		
		for (int j = 1; j <= m; ++j)
			if (i == tri[j].st && tri[j].st <= tri[j].ed) {
				e[++eSize] = pii(tri[j].up, 1);
				e[++eSize] = pii(tri[j].dn+1, -1);
				tri[j].up += tri[j].dup;
				tri[j].dn += tri[j].ddn;
				tri[j].st++;
			}
		if (0 <= i && i < n) {
			sort(e+1, e+eSize+1);
			e[eSize+1] = pii(inf, 0);
			int sum = 0;
			for (int i = 1, j; i <= eSize; i = j) {			
				for (j = i; j <= eSize && e[j].fi == e[i].fi; ++j)
					sum += e[i].se;
				
				if (e[j].fi >= 0 && e[i].fi <= n && sum & 1)
					ans += (min(e[j].fi, n) - max(0, e[i].fi));
			}
		}
		
	}

	cout << ans << endl;
}
 
