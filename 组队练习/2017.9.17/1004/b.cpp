#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef unsigned long long ll;
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
int a[] = {2146, 1, 2, 1, 2, 3, 1, 2, 1, 24, 1, 2, 1, 4, 1, 406, 1, 2, 1, 1, 1, 4, 2, 1, 1, 16, 1, 4, 1, 2};
int main(){
    int n = 2;
	cin >> n;
	ll up = a[n-1], dw = 1;
	for (int i = n-2; i >= 0; --i) {
		ll tup = a[i] * up + dw;
		ll tdw = up;
		up = tup;
		dw = tdw;
		//printf("%llu/%llu is %.20lf", up, dw, (ld) up / dw);
	}
	printf("%llu/%llu is %.20lf", up, dw, (ld) up / dw);
}
 
