#include <bits/stdc++.h>
#define gen(nd) (rand() % int(nd) + 1)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int n = 1e5, m = 1e5;
const int mod = 1e9+7, maxn = 1e6+10;

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
int main() {
	freopen("p.in","w",stdout);
	srand(time(0));
	for (int T = 1; T <= 3; ++T) {
		n = pow(10,T), m = gen(1e3);
		cout << n << " " << m << endl;
		for (int i = 1; i <= m; ++i) {
			int I = gen(n), J = gen(n), B = rand() % 101;
			while (I == J) J = gen(n);
			if (I > J) swap(I, J);
			cout << I << " " << J << " " << B << endl;
		}
		puts("");
	}
	n = 200, m = gen(1e3);
	cout << n << " " << m << endl;
	for (int i = 1; i <= m; ++i) {
		int I = gen(n), J = gen(n), B = rand() % 101;
		cout << I << " " << J << " " << B << endl;
	}
}
