#include<iostream>
#include<vector>

using namespace std;

//C=A+B
vector<int> add(vector<int>&A,vector<int>&B)//A,B两个参数  
{
	vector<int> C;
	int temp=0;//进位 
	for(int n=0; n<A.size() || n<B.size(); n++)//倒序存放，因为在最高位利于进位
	{
		if(n<A.size())	temp+=A[n];//可以递归，始终返回一个大的数组在某一侧，减去一个判断条件 eg.A.size()>b.size() 
		if(n<B.size())	temp+=B[n];
		C.push_back(temp%10);
		temp /= 10;
	}
	if(temp)//直接temp判断 
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
		A.push_back(a[n]-'0');//a中存放的是对应数字的ASCII码，减去‘0’后得到对应的数字 
	}
	
	for(int n=b.size()-1;n>=0;n--)
	{
		B.push_back(b[n]-'0');
	}
	
	auto C=add(A,B);//auto类型省去了繁杂的类型声明
	
	for(int n=C.size()-1;n>=0;n--)
	{
		cout<<C[n];
	} 
	return 0;
} 
