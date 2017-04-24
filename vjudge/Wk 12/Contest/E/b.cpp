#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXNODE=362880;

struct State
{
	char d[9];
	short f;
};
int pow[]={1,2,6,24,120,720,5040,40320};
int rot[4][9]={{1,4,2,0,3,5,6,7,8},{0,2,5,3,1,4,6,7,8},{0,1,2,4,7,5,3,6,8},{0,1,2,3,5,8,6,4,7}};
short ans[MAXNODE];
int head,tail;
State Q[MAXNODE];
int State2I(State &p)
{
	int ret=0;
	for(int i=0;i<8;i++)
		for(int j=i+1;j<9;j++) if(p.d[i]>p.d[j]) ret+=pow[7-i];
	return ret;
}
void PreCom()
{
	memset(ans,255,sizeof(ans));
	head=-1,tail=0;
	Q[0].f=0;
	for(int i=0;i<9;i++) Q[0].d[i]=i+1;
	ans[State2I(Q[0])]=0;

	while(head++<tail)
    {
		State &p=Q[head],q;
		q.f=p.f+1;
		for(int i=0;i<4;i++)
		{

			for(int j=0;j<9;j++) q.d[j]=p.d[rot[i][j]];
			int u=State2I(q);
			if(ans[u]<0)
			{
				ans[u]=q.f;
				Q[++tail]=q;
			}
		}
	}
}
void Work()
{
	State p;
	int x;

	while(scanf("%d",&x)==1)
    {
		p.d[0]=x;
		for(int i=1;i<9;i++)
		{
			scanf("%d",&x);
			p.d[i]=x;
		}
		printf("%d\n",ans[State2I(p)]);
	}
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	PreCom();
	Work();
	return 0;
}
