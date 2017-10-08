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

string s1[101010], s2[101010];
int cnt;
int main(){
	freopen("a.out","r",stdin);
	for (int i = 1; i <= 100000; ++i) cin >> s1[i];

	fclose(stdin);
	freopen("b.out","r",stdin);
	for (int i = 1; i <= 100000; ++i) cin >> s2[i];

	for (int i = 1; i <= 100000; ++i)
		if (s1[i] != s2[i])
			cout << ++cnt << " " << i << endl;
    
}
 
