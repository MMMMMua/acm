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
int a[20];
int p[20];
int d[20];
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], p[i] = i;

	int cnt = 0;
	do {
		for (int i = 1; i <= n; ++i) d[i] = 0;
		for (int i = 1; i < n; ++i)
			d[p[i]]++, d[p[i+1]]++;

		for (int i = 1; i <= n; ++i)
			if (d[i] != a[i]) goto fail;
		cnt++;
	  fail:;
	} while (next_permutation(p+1, p+n+1));

	cout << cnt;
}
   
 
