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

string zod[] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int T;
	for (scanf("%d", &T); T--; ) {
		string a, b;
		cin >> a >> b;
		int x = find(zod, zod+12, a)-zod, y = find(zod, zod+12, b)-zod;
		int z = y - x;
		if (z <= 0) z += 12;
		cout << z << endl;
	}
}
 
