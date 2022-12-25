#include<bits/stdc++.h>
using namespace std;
int r,l;
int mi=0;
int tu[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<int> mp[10000000];
int emeo[10000][10000];
void dfs(int x,int y,int step)
{
	if(emeo[x][y]==1) return;
	if(x>=r||y>=l||x<0||y<0) return;
	if(x==r-1&&y==l-1)
	{
		step+=mp[x][y];
		mi=max(step,mi);
		return;
	}
	for(int n=0;n<4;n++)
	{	int tx=x+tu[n][0];
		int ty=y+tu[n][1];
	   if(tx>=r||ty>=l||tx<0||ty<0) continue;
	emeo[x][y]=1;
	dfs(x+tu[n][0],y+tu[n][1],step+mp[x][y]);
	emeo[x][y]=0;
   }
   return;
}
int main()
 {
 	cin>>r>>l;
 	for(int n=0;n<r;n++)
 	for(int m=0;m<l;m++)
 	{
 		int g;
 		cin>>g;
 		mp[n].push_back(g);
 	}
    dfs(0,0,0);
    cout<<mi;
    return 0;
 }
