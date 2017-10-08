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
int A[maxn], B[maxn];

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
        while(~scanf("%d %d", &n, &k), n || k) {
		for (int i = 1; i <= n; ++i) gint(A[i]);
		
		while (k--) {
			int s, t;
			gint(s), gint(t);
			for (int i = s; i <= t; ++i) A[i]++;
			memcpy(B, A, sizeof(int)*(n+10));
			sort(B+1, B+n+1);

			cout << B[n+1>>1] << endl;
		}
	}
}
 
