#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Ϊ�˽����Ѷȣ�����û�н���������Ū�úܴ����ǰ�Bֱ�ӵ��� long long ���ʹ���
vector<int> mul(vector<int>& A, int B)
{
	vector<int>C;
	long long temp=0;
	for(int n=0;n<A.size()||temp!=0;n++)//temp��Ϊ0����Ҫ�����λ
	{
		if(n<A.size())	temp += A[n] * B;//����ֻʣ�½�λ��Ҫ�����������Ѿ�������ȫ
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
