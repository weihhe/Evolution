#include<iostream>
#include<cstdio>

const int N=100010;


int q[N],temp[N],g;//k递归中重复利用的量 一定要控制在递归中 

using namespace std;//归并，左右分界点 
void MergeSort(int q[],int l,int r)
{
	
	if(l>=r) return;
	int mid=(l+r)>>1;
	 MergeSort(q,l,mid); MergeSort(q,mid+1,r);
	long long z=l,y=mid+1,k=0;
	while(z<=mid&&y<=r)
	{
	if(q[z]<=q[y]) temp[k++]=q[z++];
	else 
	{
	    temp[k++]=q[y++];
	   g+=mid-z+1;
	}
}
	while(z<=mid) temp[k++]=q[z++];//一条链可能提前全部导出 
	while(y<=r)	temp[k++]=q[y++];
		
for(z=l,y=0;z<=r;z++,y++ )	q[z]=temp[y];//将temp返回到q 

}
int main()
{
	int n;
	scanf("%d",&n);
	for(int f=0;f<n;f++)
	{
		scanf("%d",&q[f]);
	}
	MergeSort(q,0,n-1);
		printf("%lld",g);
	return 0;
} 
