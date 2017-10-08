#include <bits/stdc++.h>
using namespace std;
int maxlen, T, n, t, tmp, now, pos, ans, son[200001][26], num[200001], p[200001];
char a[200010], b[200010];
queue<int> q;
void Insert(char s[])
{
    int t = 1, tmp;
    for (int i = 0; s[i]; i++)
    {
        tmp = s[i] - 97;
        if (!son[t][tmp])
            son[t][tmp] = ++pos;
        t = son[t][tmp];
    }
    num[t]++;
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        pos = 1;
		maxlen = 0;
        memset(son, 0, sizeof(son));
        memset(num, 0, sizeof(num));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", b);
            Insert(b);
			int t = strlen(b);
			if (t > maxlen)
				maxlen = t, strcpy(a, b);
        }
        q.push(1);
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
                if (son[now][i])
                {
                    for (t = p[now]; t > 0 && son[t][i] == 0; t = p[t]);
                    p[son[now][i]] = t ? son[t][i] : 1;
                    q.push(son[now][i]);
                }
        }
        t = 1;
        ans = 0;
        for (int i = 0; a[i]; i++)
        {
            tmp = a[i] - 97;
            for (; t > 0 && son[t][tmp] == 0; t = p[t]);
            t = t ? son[t][tmp] : 1;
            for (int j = t; j > 1 && num[j] > -1; j = p[j])
            {
                ans += num[j];
                num[j] = -1;
            }
        }
		if (ans == n)
			printf("%s\n", a);
		else
			puts("No");
    }
    return 0;
}
