#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50, sigma = 27;
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

int tr[maxn][sigma+1];
int fail[maxn], last[maxn], vis[maxn];
int n, T, size, maxlen;
char str[maxn], maxstr[maxn];

inline int idx(char c) { return c - 'a' + 1;}

void init() {
	for (int i = 1; i <= size; ++i)
		memset(tr[i], 0, sizeof(tr[i])), fail[i] = last[i] = vis[i] = 0;
	maxlen = 0;
	size = 1;
}

void insert(char *str, int id) {
	int x = 1, l = strlen(str);
	for (int i = 0; i < l; x = tr[x][idx(str[i++])])
		if (!tr[x][idx(str[i])]) tr[x][idx(str[i])] = ++size;
	last[id] = x;
}


void get_fail() {
	int h = 0, t = 0;
	int q[maxn];
	for (int i = 1; i <= sigma; ++i)
		tr[1][i] ? fail[q[++t] = tr[1][i]] = 1 : tr[1][i] = 1;

	while (h < t) {
		int x = q[++h];
		for (int i = 1; i <= sigma; ++i) {
			 int &T = tr[x][i]; 
			T ? fail[q[++t] = T] = tr[fail[x]][i] : T = tr[fail[x]][i];
		}
	}
}

int match(char *str) {
	int l = strlen(str);
	for (int i = 0, x = 1; i <= l; x = tr[x][idx(str[i++])])
		for (int t = x; t && !vis[t]; t = fail[t]) vis[t] = 1;

	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += vis[last[i]];
	return cnt;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    for (scanf("%d",&T); T--; ) {
		scanf("%d",&n);

		init();
		for (int i = 1, t; i <= n; ++i) {
			scanf("%s", str), insert(str, i);
			if ((t = strlen(str)) > maxlen)
				maxlen = t, strcpy(maxstr, str);
		}
		
		get_fail();
		
		if (match(maxstr) == n)
			printf("%s\n", maxstr);
		else
			puts("No");
	}
}
