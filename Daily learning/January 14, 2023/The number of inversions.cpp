#include<iostream>
#include<cstdio>

const int N=100010;


int q[N],temp[N],g;//k�ݹ����ظ����õ��� һ��Ҫ�����ڵݹ��� 

using namespace std;//�鲢�����ҷֽ�� 
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
	while(z<=mid) temp[k++]=q[z++];//һ����������ǰȫ������ 
	while(y<=r)	temp[k++]=q[y++];
		
for(z=l,y=0;z<=r;z++,y++ )	q[z]=temp[y];//��temp���ص�q 

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
