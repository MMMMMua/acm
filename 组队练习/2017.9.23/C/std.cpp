#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

int a[310][310], b[310][310];

int main() {
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
		int n, m, p;
	while (scanf("%d%d%d", &n, &m, &p) != EOF) {

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}

		int ans = -INF;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int t = a[i][j];
				a[i][j] = p;

				memset(b, 0, sizeof b);
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= m; ++j) {
						b[i][j] = a[i][j] + b[i-1][j];
					}
				}

				int maxx = -INF;
				for (int i1 = 0; i1 < n; ++i1) {
					for (int i2 = i1 + 1; i2 <= n; ++i2) {
						int sum = 0;
						for (int k = 1; k <= m; ++k) {
							if (sum <= 0) sum = (b[i2][k] - b[i1][k]);
							else sum += (b[i2][k] - b[i1][k]);

							maxx = max(sum, maxx);
						}
					}
				}

				ans = max(ans, maxx);
				a[i][j] = t;
			}
		}

		printf("%d\n", ans);
	}
}

