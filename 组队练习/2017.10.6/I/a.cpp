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

int n, k;
int x[maxn], m[maxn];
vector<pii> q[2];

ll calc(vector<pii> &v) {
	sort(v.begin(), v.end());
	ll ret = 0;
	while (v.size()) {
		ll cnt = 0;
		bool flag = true;
		while (v.size())
			if (flag) {
				ll times = v.back().se / k;
				ret += times * 2 * v.back().fi;
				v.back().se %= k;
				if (v.back().se != 0) {
					ret += 2 * v.back().fi;
					cnt = k - v.back().se;
					flag = false;
				}
				v.pop_back();
			}
			else if (v.back().se > cnt) {
				v.back().se -= cnt;
				flag = true;
			}
			else {
				cnt -= v.back().se;
				v.pop_back();
			}
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> m[i];
		q[x[i] > 0].push_back(pii(abs(x[i]), m[i]));
	}

	cout << calc(q[0]) + calc(q[1]);
}

