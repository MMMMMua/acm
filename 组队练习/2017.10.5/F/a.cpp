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
arrn pre, aft, nlefp, nlefa;

int takeOut(int f[], int nlf[]) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (!nlf[i]) {
			for (int k = i; k; k = f[k], cnt++);
			cnt--;
		}

	return cnt;
}

int putIn() {
	int sav = 0;
	for (int i = 1; i <= n; ++i)
		if (!nlefp[i] && !nlefa[i] && pre[i] == aft[i]) {
			for (int j = i, k = i; j && j == k; j = pre[j], k = aft[k])
				sav++;
			sav--;
		}

	return sav * 2;		
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
    scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d", &pre[i]), nlefp[pre[i]] = 1;
	for (int i = 1; i <= n; ++i) scanf("%d", &aft[i]), nlefa[aft[i]] = 1;

	int step1 = takeOut(pre, nlefp) + takeOut(aft, nlefa);
	int step2 = putIn();

	cout << step1 - step2 << endl;		
}
 
