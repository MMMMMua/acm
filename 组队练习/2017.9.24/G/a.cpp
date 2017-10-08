#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld pi = 3.14159;

typedef int arrn[maxn];
typedef ll arrm[maxn];

template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()){
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

ld r[20], theta[20], R;
int l, k;

ld solve(ld theta, ld cons) {
	ld L = 0, R = theta;
	ld G = tan(theta) + cons;
	
	for (int i = 1; i <= 200; ++i) {
		ld mid = (L + R) / 2;
		ld F = tan(mid) + 1 / cos(mid);

		if (F < G) L = mid;
		else R = mid;
	}

	return (L + R) / 2;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> l >> R;

	r[1] = 2 * R / sqrt(3) - R;
	theta[1] = acos(R / (R + r[1]));

	for (int i = 2; i <= 10; ++i) {
		theta[i] = solve(theta[i-1], 1-r[i-1]/R);
		r[i] = R / cos(theta[i]) - R;
	}

	for (int i = 1; i <= l; ++i) {
		scanf("%d",&k);
		printf("%d %d\n",k, int(r[k]));
	}
	scanf("%d",&k);
}
 
