#include <bits/stdc++.h>
using namespace std;
int n, m, x, t, sum, ans, a[51];
double f;
bool Read(int &x)
{
    char c = 0;
    x = 0;
    for (; c < '0' || c > '9'; c = getchar());
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return c != '\n';
}
int main()
{
    scanf("%d%lf", &n, &f);
    while (~scanf("%d", &x))
    {
        a[++m] |= 1 << (x - 1);
        while (getchar() != '\n')
        {
            scanf("%d", &x);
            a[m] |= 1 << (x - 1);
        }
    }
    for (int i = 1; i < 1 << n; i++)
    {
        sum = 0;
        for (int j = 1; j <= m; j++)
            if ((i & a[j]) == i)
                sum++;
        if (sum >= m * f)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
