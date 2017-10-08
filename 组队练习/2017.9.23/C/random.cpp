#include<bits/stdc++.h>
using namespace std;

int random(int l, int r)
{
    if (r - l + 1 >= 32768)
        return rand() * rand() % (r - l + 1) + l;
    else return rand() % (r - l + 1) + l;
}

int main()
{
	freopen("a.in","w",stdout);
    srand((unsigned)time(NULL));
    int T = 2;
    int N=300, Ai=1000, n, m, i, j;
    while (T--)
    {
    	n = random(250, N);		
    	m = random(250, N);

		// n = random(1, N);
    	// m = random(1, N);
 
    	printf("%d %d %d\n", n, m, random(-Ai, Ai));
    	for (i = 1; i <= n; ++i)
    	{
    		for (j = 1; j <= m; ++j)
    			printf("%d ", random(-Ai, Ai));
    		puts("");
		}
	}
    return 0;
}
