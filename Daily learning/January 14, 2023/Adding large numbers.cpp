#include<iostream>
#include<vector>

using namespace std;

//C=A+B
vector<int> add(vector<int>&A,vector<int>&B)//A,B��������  
{
	vector<int> C;
	int temp=0;//��λ 
	for(int n=0; n<A.size() || n<B.size(); n++)//�����ţ���Ϊ�����λ���ڽ�λ
	{
		if(n<A.size())	temp+=A[n];//���Եݹ飬ʼ�շ���һ�����������ĳһ�࣬��ȥһ���ж����� eg.A.size()>b.size() 
		if(n<B.size())	temp+=B[n];
		C.push_back(temp%10);
		temp /= 10;
	}
	if(temp)//ֱ��temp�ж� 
	{
		C.push_back(1);
	}
	return C;
}

int main()
{
	string a,b;
	vector<int> A,B;
	
	cin>>a>>b;
	
	for(int n=a.size()-1;n>=0;n--)
	{
		A.push_back(a[n]-'0');//a�д�ŵ��Ƕ�Ӧ���ֵ�ASCII�룬��ȥ��0����õ���Ӧ������ 
	}
	
	for(int n=b.size()-1;n>=0;n--)
	{
		B.push_back(b[n]-'0');
	}
	
	auto C=add(A,B);//auto����ʡȥ�˷��ӵ���������
	
	for(int n=C.size()-1;n>=0;n--)
	{
		cout<<C[n];
	} 
	return 0;
} 
