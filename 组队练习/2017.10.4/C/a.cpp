#include <bits/stdc++.h>
#define fi first
#define se second
#define x first
#define y second
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, int> Point;
typedef pair<Point, Point> Segment;

const int maxn = 2010, maxm = 4e6+100;

int w, n, edg, dfn, tot, sz;
int vis[maxn], la[maxn];
int to[maxm], nt[maxm];
pii rel[maxm];
Point p[maxn];
Segment s[maxn];

inline ll Cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool judge(Segment a, Segment b) {	
	return Cross(a.x, a.y, b.x) * Cross(a.x, a.y, b.y) < 0 && Cross(b.x, b.y, a.x) * Cross(b.x, b.y, a.y) < 0;
}

void add_edge(int x, int y) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg;
	to[++edg] = x, nt[edg] = la[y], la[y] = edg;
}

void build() {
	tot = 1;
	int p[maxn][2];
	
	for (int i = 1; i <= n; ++i)
		p[i][0] = ++tot, p[i][1] = ++tot;
	for (int i = 1; i <= sz; ++i) {
		add_edge(p[rel[i].fi][0], p[rel[i].se][1]);
		add_edge(p[rel[i].se][0], p[rel[i].fi][1]);
	}
}

bool dfs(int x) {
	vis[x] = dfn;
	if (vis[x] == vis[x^1]) return false;
	for (int i = la[x]; i; i = nt[i])
		if (vis[to[i]] == 0)
			if (dfs(to[i]) == false)
				return false;
	return true;		
}

bool twosat() {
	for (int i = 2; i <= tot; ++i)
		if (vis[i] == 0) {
			++dfn;
			if (dfs(i) == false)
				return false;
		}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	scanf("%d %d", &w, &n);
	for (int i = 1; i <= w; ++i)
		scanf("%d %d", &p[i].x, &p[i].y);

	for (int i = 1, id; i <= n; ++i) {
		scanf("%d %d %d", &id, &s[i].x2, &s[i].y2);
		s[i].x = p[id];
	}

	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
			if (judge(s[i], s[j]))
				rel[++sz] = pii(i, j);

	build();

	bool res = twosat();
	puts(res ? "possible" : "impossible");
	
}
