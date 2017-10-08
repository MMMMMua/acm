#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(i = a; i <= b; ++i)
#define rev(i,a,b) for(i = a; i >= b; --i)

const int maxn = 3.5e5, inf = 0x3f3f3f3f;

typedef int arrn[maxn];

int n, T, len, k, kase, len1;
arrn c, t1, t2, sa, rnk, height, str, lg, flag, tflag, tlen;
int g[21][maxn];
char tstr[maxn];

int cmp(int y[], int a, int b, int c){
	return y[a] == y[b] && y[a+c] == y[b+c];
}

void build(int *s, int n, int m){
	int i, j, p, *x = t1, *y = t2;
	
	rep(i, 0, m) c[i] = 0;
	rep(i, 1, n) c[x[i] = s[i]]++;
	rep(i, 1, m) c[i] += c[i-1];
	rev(i, n, 1) sa[c[x[i]]--] = i;
	
	for(j = 1, p = 0; j < n && p < n; j <<= 1, m = p, p = 0){
		rep(i, n-j+1, n) y[++p] = i;
		rep(i, 1, n) if(sa[i] > j) y[++p] = sa[i] - j;
		rep(i, 0, m) c[i] = 0;
		rep(i, 1, n) c[x[y[i]]]++;
		rep(i, 1, m) c[i] += c[i-1];
		rev(i, n, 1) sa[c[x[y[i]]]--] = y[i];
		for(swap(x, y), x[sa[1]] = 1, p = 1, i = 2; i <= n; ++i)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p : ++p;
	}
}

void calc_height(int *s, int n){
	for(int i = 1; i <= n; ++i) rnk[sa[i]] = i;
	
	for(int i = 1, k = 0, j; i <= n; height[rnk[i++]] = k)
		for(k?k--:0, j = sa[rnk[i]-1]; str[i+k] == str[j+k]; ++k);
}

void init_rmq(int a[]){
	lg[0] = -1;
	for(int i = 1; i <= len; ++i)
		g[0][i] = a[i], lg[i] = lg[i/2] + 1;
	for(int j = 1; j <= 20; ++j)
		for(int i = 1; i+(1<<j)-1 <= len; ++i)
			g[j][i] = min(g[j-1][i], g[j-1][i+(1<<(j-1))]);	
}

int lcp(int l, int r){
	if (l > r) swap(l, r);
	l++;
	int k = lg[r-l+1];
	return min(g[k][l], g[k][r-(1<<k)+1]);
}

void init() {
	for (int i = 1; i <= len; ++i)
		flag[i] = 0;
	len = 0;	
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	for (scanf("%d" ,&T); T--; ) {
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; ++i) {
			scanf("%s", tstr+1);
			int tlen = strlen(tstr+1);
			if (i == 1) len1 = tlen;
			for (int j = 1; j <= tlen; ++j)
				str[++len] = tstr[j]+n, tflag[len] = (i != 1);
			str[++len] = i;
			tflag[len] = 2;
		}

		build(str, len, len+200);
		calc_height(str, len);
		init_rmq(height);
		for (int i = 1; i <= len; ++i) flag[rnk[i]] = tflag[i];
		
		int ans = inf, id;
		for (int i = len, l = i, r = i+1; i >= 1; --i)
			if (flag[i]) {
				if (flag[i] == 1) r = i;
			}
			else {
				if (l > i) l = i;
				while (l >= 1 && flag[l] != 1) l--;
				int llcp = (l == 0 ? 0 : lcp(l, i));
				int rlcp = (r == len+1 ? 0 : lcp(r, i));
				int tans = max(llcp, rlcp)+1;
				if (tans <= ans && tans <= len1 - sa[i] + 1)
					ans = tans, id = i;
			}

		printf("Case #%d: ", ++kase);
		if (ans != inf)
			for (int i = 1; i <= ans; ++i)
				putchar(char(str[sa[id]+i-1]-n));
		else
			printf("Impossible");
		puts("");
	}
} 
