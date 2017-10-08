#include <bits/stdc++.h>
#define gen(nd) (rand() % int(nd) + 1)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int n = 1e5, m = 1e5,mod = 1e9+7, maxn = 1e6+10, t = 1e5;

int seq[maxn], fa[maxn];
pii Pair[maxn];

void gen_sequence(int len, int rng) {
	for(int i = 1; i <= len; ++i) seq[i] = gen(rng);
}
void gen_tree(int len) {
	for (int i = 2; i <= len; ++i) fa[i] = gen(i-1);
}
void gen_rng(int rep, int len) {
	for (int i = 1; i <= rep; ++i) {
		int l = gen(len), r = gen(len);
		if (l > r) swap(l, r);
		Pair[i] = make_pair(l, r);
	}
}
void output(int seq[], int len) {
    for (int i = 1; i <= len; ++i) cout << seq[i] << " ";
    cout << endl;
}

char getd() {
	int x = gen(4);
	if (x == 1) return 'U';
	if (x == 2) return 'D';
	if (x == 3) return 'L';
	if (x == 4) return 'R';
					
}
set<pii> s;
int main() {
	freopen("a.in","w",stdout);
	srand(time(0));
	cout << n << " " << (ll)1e18 << endl;
	for (int i = 1; i <= n; ++i) {
		int x = gen(1000), y = gen(1000);
		while (s.count(pii(x, y)))
			x = gen(1000), y = gen(1000);
		cout << x << " " << y << " " << getd() << endl;
		// int x = 1,  y = i;		
		// cout << x << " " << y << " " << (i == 1 ? 'U' : 'D') << endl;
	}										
}
 
