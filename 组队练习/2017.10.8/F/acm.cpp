#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int n,m,k;

char ans[5000];
char s[200][5000];

bool contain(char *s,char *t,int n)
{
	int i,j;
	for(i=0;s[i+n-1]!=0;i++)
	{
		for(j=0;j<n;j++)
			if(s[i+j]!=t[j]) break;
		if(j==n) return true;
	}
	return false;
}

bool getans(int k)
{
	bool ok=false;
	ans[0]='z'+1;
	int i,j;
	int l=strlen(s[0]);
	for(i=0;i+k<=l;i++)
	{
		for(j=1;j<n;j++)
			if(contain(s[j],s[0]+i,k)) break;
		if(j==n)
		{
			char tmp=s[0][i+k];
			s[0][i+k]=0;
			if(strcmp(s[0]+i,ans)<0) strcpy(ans,s[0]+i);
			s[0][i+k]=tmp;
			ok=true;
		}
	}
	return ok;
}

void gen()
{
	FILE* fi=fopen("a.in","w");
	srand(time(0));
	int T=rand()%30+1; //max 42
	fprintf(fi,"%d\n",T);
	for(int t=1;t<=T;t++)
	{
		int n=rand()%20+1; //max 50
		fprintf(fi,"%d\n",n);
		for(int i=0;i<n;i++)
		{
			int m=rand()%100+1; //max 500
			int j;
			for(j=0;j<m;j++)
				s[i][j]=rand()%5+'a'; //max 26
			s[i][j]=0;
			fprintf(fi,"%s\n",s[i]);
		}
	}
	fclose(fi);
}

int main()
{
	gen();
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	int i,j,t,cur,T,tu,tv,tw;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		m=strlen(s[0]);
		for(i=1;i<=m;i++)
			if(getans(i)) break;
		printf("Case #%d: ",t);
		if(i==m+1) printf("Impossible\n");
		else printf("%s\n",ans);
	}
	return 0;
}
