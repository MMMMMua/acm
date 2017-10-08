#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <ll, int> pii;

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
ll t;
ll d[maxn];
set<pii> vx[maxn], vy[maxn];
ll dx[maxn], dy[maxn];
int xsz, ysz;
priority_queue<pii, vector<pii>, greater<pii> > q;
bool flag[maxn];

struct P {
	ll x, y, tx, ty;
	ll t;
	char d;
	P() {
		t = INF;
	}
} p[maxn];


void discreation(ll x[], int &sz) {
	sort(x+1, x+sz+1);
	sz = unique(x+1, x+sz+1) - x - 1;
}

void bfs() {
	for (int i = 1; i <= n; ++i) d[i] = INF, flag[i] = false;
	d[1] = 0;
	q.push(pii(0, 1));

	int cnt = 0;
	while (q.size()) {
		while (q.size() && flag[q.top().se])
			q.pop();

		if (q.empty()) break;

		pii T = q.top();
		q.pop();

		int x = T.se;
		flag[x] = true;
		d[x] = T.fi;

		vx[p[x].tx].erase(pii(p[x].y, x));
		vy[p[x].ty].erase(pii(p[x].x, x));
		
		// cnt ++;
		// if (cnt > n) 1/0;
		// if (flag[x]) continue;
		// else flag[x] = true;

		if (p[x].d == 'D') {
			set<pii> &S = vx[p[x].tx];
			set<pii>::iterator it = S.lower_bound(pii(p[x].y, x));
			if (it != S.begin())
				for (it--; ; it--) {
					int y = it->se;
					ll dis = d[x] + abs(p[x].y - p[y].y);
					if (d[y] > dis) {
						d[y] = dis;
					}
					q.push(pii(d[y], y));
					if (p[y].d == p[x].d)
						break;
					if (it == S.begin()) break;
				}
		}
		else if (p[x].d == 'U') {
			set<pii> &S = vx[p[x].tx];
			set<pii>::iterator it = S.lower_bound(pii(p[x].y, x));
			if (it != S.end())
				for (; it != S.end(); it++) {
					int y = it->se;
					ll dis = d[x] + abs(p[x].y - p[y].y);
					if (d[y] > dis) {
						d[y] = dis;
					}
					q.push(pii(d[y], y));
					if (p[y].d == p[x].d)
						break;
				}
		}
		else if (p[x].d == 'L') {
			set<pii> &S = vy[p[x].ty];
			set<pii>::iterator it = S.lower_bound(pii(p[x].x, x));
			
			if (it != S.begin())
				for (--it; ; it--) {
					int y = it->se;
					ll dis = d[x] + abs(p[x].x - p[y].x);
					if (d[y] > dis ) {
						d[y] = dis;
					}
					q.push(pii(d[y], y));
					if (p[y].d == p[x].d)
						break;
					if (it == S.begin()) break;
				}
		}
		else if (p[x].d == 'R') {
			set<pii> &S = vy[p[x].ty];
			set<pii>::iterator it = S.lower_bound(pii(p[x].x, x));
			
			if (it != S.end())
				for (; it != S.end(); it++) {
					int y = it->se;
					ll dis = d[x] + abs(p[x].x - p[y].x);
					if (d[y] > dis ) {
						d[y] = dis;
					}
					q.push(pii(d[y], y));
					if (p[y].d == p[x].d)
						break;
				}
		}
	}
}

void Nxt(P p, ll t) {
	ll dx, dy;
	switch (p.d) {
		case 'U': dx = 0, dy = 1; break;
		case 'D': dx = 0, dy = -1; break;
		case 'L': dx = -1, dy = 0; break;
		case 'R': dx = 1, dy = 0; break;
	}

	printf("%lld %lld\n", (ll)p.x+t*dx, (ll)p.y+t*dy);
}

int gpos(ll x[], int sz, ll y) {
	return lower_bound(x+1, x+sz+1, y) - x;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d %lld", &n, &t);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld %lld %c", &p[i].x, &p[i].y, &p[i].d);
		dx[++xsz] = p[i].x, dy[++ysz] = p[i].y;
	}

	discreation(dx, xsz);
	discreation(dy, ysz);

	for (int i = 1; i <= n; ++i) {
		vx[p[i].tx = gpos(dx, xsz, p[i].x)].insert(pii(p[i].y, i));
		vy[p[i].ty = gpos(dy, ysz, p[i].y)].insert(pii(p[i].x, i));
	}

	bfs();

	for (int i = 1; i <= n; ++i)
		if (d[i] >= t)
			printf("%lld %lld\n", p[i].x, p[i].y);
		else
			Nxt(p[i], t - d[i]);
}
