#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iostream>
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

int T, G, kase;
string WSchool, Ecs[8][25], Ecf[25];
set<string> S;

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T--; ) {
		cin >> G >> WSchool;

		for (int i = 1; i <= 5; ++i)
			for (int j = 1; j <= 20; ++j) cin >> Ecs[i][j];

		for (int i = 1; i <= 20; ++i) cin >> Ecf[i];

		cout << "Case #" << ++kase << ": ";

		bool flag = true;
		for (int x = G; x >= 0; --x) {
			S.clear();
			int cntX = 0, cntY = 0;
			for (int i = 1; i <= 20 && cntX < x; ++i)
				for (int j = 1; j <= 5 && cntX < x; ++j)
					if (S.count(Ecs[j][i]) == 0)
						S.insert(Ecs[j][i]), cntX++;

			for (int i = 1; i <= 20 && cntY < G-x; ++i)
					if (S.count(Ecf[i]) == 0)
						S.insert(Ecf[i]), cntY++;
			
			if (S.count(WSchool) == 0) {
				cout << G-x << endl;
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "ADVANCED!" << endl;		
	}
}
