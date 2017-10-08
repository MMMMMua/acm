#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 5e5+50, maxm = 1e5+50;
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

ll n;
int m, sz;
int to[maxn][2];
int deg[maxn];
int seq[maxn];
int sta[maxn];
ll num[maxn];
char s[20];

void topsort() {
	int h = 0, t = 0;
	static int q[maxn];
	q[++t] = 1;
	while (h < t) {
		int x = q[++h];
		seq[++sz] = x;
		if (--deg[to[x][0]] == 0) q[++t] = to[x][0];
		if (--deg[to[x][1]] == 0) q[++t] = to[x][1];				
	}
}
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		scanf("%s %d %d", s, &to[i][0], &to[i][1]);
		deg[to[i][0]]++, deg[to[i][1]]++;
		sta[i] = (s[0] == 'R');
	}
	
	topsort();

	num[1] = n;
	for (int i = 1; i <= sz; ++i) {
		int x = seq[i];
		if (num[x] & 1) {
			num[to[x][sta[x]]] += num[x] / 2 + 1;
			num[to[x][sta[x]^1]] += num[x] / 2;
			sta[x] ^= 1;
		}
		else {
			num[to[x][sta[x]]] += num[x] / 2;
			num[to[x][sta[x]^1]] += num[x] / 2;			
		}
	}

	for (int i = 1; i <= m; ++i)
		putchar(sta[i] ? 'R' : 'L');
}
 
