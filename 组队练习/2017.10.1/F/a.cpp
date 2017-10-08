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

int T, n, m;
vector<int> jok[maxn];
int sta[maxn];

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    for (cin >> T; T--; ) {
		cin >> n >> m;

		for (int i = 1; i <= n; ++i)
			jok[i].clear(), sta[i] = 1;
		while (m--) {
			int x, l, k;			
			cin >> x >> l >> k;

			for (int i = max(1, x-k); i <= min(n,x+k); ++i)
				if (find(jok[i].begin(), jok[i].end(), l) == jok[i].end())
					jok[i].push_back(l), sta[i] = 0; //on ground
				else
					jok[i].push_back(l), sta[i] = 1;
		}

		for (int i = 1; i <= n; ++i)
			cerr << *jok[i].rbegin() << endl;
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += sta[i];

		cout << ans << endl;
	}
}
 
