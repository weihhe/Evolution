#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Ϊ�˽����Ѷȣ�����û�н���������Ū�úܴ����ǰ�Bֱ�ӵ���int���ʹ���
//����һ��Ӹ�λ��ʼ��
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
	reverse(C.begin(), C.end());//��������������ĵ�һλ�Ǹ�λ����������Ӧ�����ʽ 
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
	for (int n = a.size() - 1; n >= 0; n--)//Ϊ�˱���ͳһ�Ӽ��˳�ʱ�����Դ����ͳһ����Ȼ���ֵ��Ŵ洢
	{
		A.push_back(a[n] - '0');
	}
	auto C = mul(A, B, r);//���͵��ǵ�ַ ��
	for (int n = C.size() - 1; n >= 0; n--)
	{
		cout << C[n];
	}
	cout <<endl<<r;
	return 0;
}
