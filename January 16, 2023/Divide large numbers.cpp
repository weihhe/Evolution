#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//为了降低难度，这里没有将两个数都弄得很大，我们把B直接当成int类型处理
//除法一般从高位开始算
vector<int> mul(vector<int>& A, int &B,int &D)
{
	D = 0;
	vector<int>C;
	for (int n = A.size()-1; n>=0; n--)
	{

		D= D*10+A[n];
		C.push_back(D/B);
		D%=B;
	}
	reverse(C.begin(), C.end());//由于我们算出来的第一位是高位，调整后适应输出方式 
	while (C.back() == 0 && C.size() > 1) C.pop_back();
	return C;
}
int main()
{
	string a;
	int B;
	int r;
	vector<int>A;
	cin >> a >> B;
	for (int n = a.size() - 1; n >= 0; n--)//为了便于统一加减乘除时运算的源数据统一，仍然保持倒着存储
	{
		A.push_back(a[n] - '0');
	}
	auto C = mul(A, B, r);//发送的是地址 ！
	for (int n = C.size() - 1; n >= 0; n--)
	{
		cout << C[n];
	}
	cout <<endl<<r;
	return 0;
}
