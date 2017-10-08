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

int f[20], p[20];
vector<int> v;
int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	f[0] = 1;
	for (int i = 1; i <= 12; ++i) f[i] = f[i-1] * i;

	for (int i = 1; i <= 9; ++i) p[i] = i;

	do {
		// for (int i = 1; i <= 9; ++i)
		// 	printf("%d",p[i]);
		// printf(" ");
		int id = 0;
		for (int i = 9; i >= 1; --i) id += f[i] * (p[i] - 1) ;
		v.push_back(id);
	} while (next_permutation(p+1, p+10));

	sort(v.begin(), v.end());

	// for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	// 	cout << *it << endl;

	cout << v.size() << " " << unique(v.begin(), v.end()) - v.begin() << endl;
		
}
 
