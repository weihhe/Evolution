#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//为了降低难度，这里没有将两个数都弄得很大，我们把B直接当成 long long 类型处理
vector<int> mul(vector<int>& A, int B)
{
	vector<int>C;
	long long temp=0;
	for(int n=0;n<A.size()||temp!=0;n++)//temp不为0，仍要处理进位
	{
		if(n<A.size())	temp += A[n] * B;//可能只剩下进位需要处理，而数组已经遍历完全
		C.push_back(temp % 10);
		temp /= 10;
	}
	while (C.back() == 0 && C.size() > 1) C.pop_back();
	return C;
}
int main()
{
	string a;
	int B;
	vector<int>A;
	cin >> a >> B;
	for (int n = a.size() - 1; n >= 0; n--)
	{
		A.push_back(a[n] - '0');
	}
	auto C = mul(A, B);
	for (int n = C.size() - 1; n >= 0; n--)
	{
		cout << C[n];
	}
	return 0;
}
