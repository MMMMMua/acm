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

int n;
int a[maxn];
set<pii> s;

int main(){
	freopen("a.in","r",stdin);
    cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], s.insert(pii(a[i], i));

	int cnt = 0;
	set<pii>::iterator p;
	while ((p = s.lower_bound(pii(0, 0))) != s.begin()) {
		p--;
		int x = p->se;
		s.erase(pii(a[x], x));
		s.erase(pii(a[(x+n-2)%n+1], (x+n-2)%n+1));
		s.erase(pii(a[x%n+1], x%n+1));

		a[x] = -a[x];
		a[(x+n-2)%n+1] -= a[x];
		a[x%n+1] -= a[x];
			
		s.insert(pii(a[x], x));
		s.insert(pii(a[(x+n-2)%n+1], (x+n-2)%n+1));
		s.insert(pii(a[x%n+1], x%n+1));
		++cnt;
	}

	cout << cnt;
}
 
