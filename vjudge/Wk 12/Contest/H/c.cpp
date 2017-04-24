#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
using namespace std;

const int M = 90001; //myhash函数，取余的数

int snow[100005][6]; //存储雪花信息
vector<int> myhash[M]; //myhash表，表中存储的是snow数组的下标

bool isSame(int a, int b)//判断a与b是否同样 
{
	for(int i=0;i<6;i++)
	{
		//顺时针
		if((snow[a][0] == snow[b][i] &&
					snow[a][1] == snow[b][(i+1)%6] &&
					snow[a][2] == snow[b][(i+2)%6] &&
					snow[a][3] == snow[b][(i+3)%6] &&
					snow[a][4] == snow[b][(i+4)%6] &&
					snow[a][5] == snow[b][(i+5)%6])
				||   //逆时针
				(snow[a][0] == snow[b][i] &&
				 snow[a][1] == snow[b][(i+5)%6] &&
				 snow[a][2] == snow[b][(i+4)%6] &&
				 snow[a][3] == snow[b][(i+3)%6] &&
				 snow[a][4] == snow[b][(i+2)%6] &&
				 snow[a][5] == snow[b][(i+1)%6]))

			return true;
	}
	return false;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("h.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int ok = 0;
		int n;
		int i,j;
		cin>>n;
		for( i = 0; i < n; i++) 
			for( j = 0; j < 6; j++)
				cin>>snow[i][j];

		int sum, key;
		for (int i = 0; i < M; ++i) myhash[i].clear();
		for(i = 0; i < n; i++) 
		{
			sum = 0;//求出雪花六个花瓣的和
			for( j = 0; j < 6; j++) 
				sum += snow[i][j];
			key = sum % M; //求出key

			//判断是否与myhash表中myhash[key]存储的雪花相同
			for(vector<int>::size_type j = 0; j < myhash[key].size(); j++) 
			{
				if(isSame(myhash[key][j], i))//如相同 
				{
					cout<<"Twin snowflakes found."<<endl;
					ok = 1;
					break;
				}
			}
			if (ok) {
				break;
			}
			myhash[key].push_back(i);//若没找到相同的 
		}
		if (ok == 0) 
			cout<<"No two snowflakes are alike."<<endl;
	}
	return 0;
}
