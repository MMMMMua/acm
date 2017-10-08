#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int n,m,b;
bool map[300][300];

void newfile()
{
	srand(time(0));
	FILE* f=fopen("j.in","w");
	int n=rand()%300+1;
	int a=rand()%101;
	// int n=rand()%30+1;
	// int a=rand()%4;
	fprintf(f,"%d\n%d\n",n,a);
	for(int i=0;i<a;i++)
		fprintf(f,"%d %d %d %d\n",rand()%(n+1),rand()%(n+1),rand()%(2*n)+1,rand()%4);
	fclose(f);
}

int dr[]={1,1,-1,-1};
int dc[]={-1,1,1,-1};

int main()
{
	int i,j,t,tu,tv,l,d,T,ans;
	newfile();
	freopen("j.in","r",stdin);
	freopen("j.diff","w",stdout);
	scanf("%d%d",&n,&m);
	memset(map,false,sizeof map);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&tu,&tv,&l,&d);
		if(d==0) tv--;
		else if(d==2) tu--;
		else if(d==3) tv--,tu--;
		for(j=0;j<l;j++)
			for(int k=0;k<l-j;k++)
			{
				int tr=tu+dr[d]*j;
				int tc=tv+dc[d]*k;
				if(tr>=0&&tr<n&&tc>=0&&tc<n)
					map[tu+dr[d]*j][tv+dc[d]*k]^=1;
			}
	}
	int sum=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sum+=map[i][j];
	printf("%d\n",sum);
	return 0;
}
