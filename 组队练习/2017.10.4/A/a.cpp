#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 3e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gi(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m;
pii p[maxn];
multiset<int> s;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    gi(n), gi(m);

	for (int i = 1; i <= n; ++i)
		gi(p[i].fi), gi(p[i].se), p[i].se += p[i].fi;

	sort(p+1, p+n+1);


	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (s.size() && p[i].fi - *s.begin() > m) s.erase(s.begin());

		if (s.size() && *s.begin() <= p[i].fi)
			s.erase(s.begin()), s.insert(p[i].se);
		else
			s.insert(p[i].se), ans++;
	}

	cout << n - ans << endl;
}
 
