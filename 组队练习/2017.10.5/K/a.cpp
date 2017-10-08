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


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

char str[maxn];
int n, scr;
int sz[2];
int d[2][maxn], c[2][maxn];
vector<int> v;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    scanf("%s", str+1);
	n = strlen(str+1);
	scr = 1;
	for (int i = 1; i < n; ++i) {
		c[i&1][++sz[i&1]] = (str[i] != str[i+1]);
		d[i&1][sz[i&1]] = i;
		scr += c[i&1][sz[i&1]];
	}

	for (int i = 0; i <= 1 && scr < n/3*2; ++i)
		for (int j = 1; j < sz[i] &&  scr < n/3*2; ++j)
			if (c[i][j] == 0 && c[i][j+1] == 0) {
				scr += 2;
				v.push_back(d[i][j]+d[i][j+1]>>1);
				c[i][j] = c[i][j+1] = 1;
			}
	for (int i = 0; i <= 1 && scr < n/3*2; ++i)
		for (int j = 1; j < sz[i]-1 && scr < n/3*2; ++j)
			if (c[i][j] == 0 && c[i][j+1] == 1 && c[i][j+2] == 0) {
				scr += 2;
				v.push_back(d[i][j]+d[i][j+1]>>1);
				v.push_back(d[i][j+1]+d[i][j+2]>>1);
				c[i][j] = c[i][j+2] = 1;
			}
	
	for (int i = 0; i <= 1 && scr < n/3*2; ++i)
		for (int j = 1; j < sz[i]-2 && scr < n/3*2; ++j)
			if (c[i][j] == 0 && c[i][j+1] == 1 && c[i][j+2] == 1 && c[i][j+3] == 0) {
				scr += 2;
				v.push_back(d[i][j]+d[i][j+1]>>1);
				v.push_back(d[i][j+1]+d[i][j+2]>>1);
				v.push_back(d[i][j+2]+d[i][j+3]>>1);
				c[i][j] = c[i][j+3] = 1;
			}
	
	assert(scr >= n/3*2);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]);
}
 
