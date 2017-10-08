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

Point mov(Point vertex, Point direction) {
	return vertex + (delta * direction);
}

Point center(Point poly[], int size) {
	double sx = 0, sy = 0, sz = 0;

	for (int i = 1; i <= size; ++i)
		sx += poly[i].x, sy += poly[i].y, sz += poly[i].z;

	return Point(sx / size, sy / size, sz / size);
}


// bool check_valid(Point poly[], int size, Point view, Point endian) {
// 	Point itr = intersect(poly, size, view, endian);
	
// }
bool outside(Point poly[], int size, Point ptr) {
	Point res[] = {};

	for (int i = 1; i <= size; ++i)
		res[i] = ((ptr - poly[i]) | (ptr - poly[(i-1)%size+1]));

	for (int i = 1; i <= size; ++i)
		if (res[i] & res[(i-1)%size+1] < 0)
			return false;
	return true;	
}

bool check_plane(Point Poly[maxn][], int size[], int id, int total, Point view) {
	for (int i = 1; i <= size[id]; ++i) {
		bool flag = true;
		for (int j = 1; flag && j <= total; ++j)
			if (j != id) {
				Point itr = intersect(Poly[j], size[j], view, Poly[id][i]);
				flag &= outside(Poly[j], size[j], itr);
			}
	}

	return false;
}

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
}
 
