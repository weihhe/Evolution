#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int>& A, vector<int>& B)//A>=B ����TRUE FLASE
{
	if (A.size() != B.size()) return A.size() > B.size();//�����ж�λ����λ����ͬ��A>B���� TRUE
	for (int n = A.size() - 1; n >= 0; n--)
	{
		if (A[n] != B[n])
		{
			return A[n] > B[n];//�ڳ�����ͬʱ���ȽϽϸ�λԪ�صĴ�С
		}
		return true;//��A,B��ȫһ����ʱ��ͬ������TRUE
	}
}
vector<int> sub(vector<int>& A, vector<int>& B)//��֤��A>=B
{
	vector<int>C;
	for (int n = 0, temp = 0; n < A.size(); n++)
	{
		temp = A[n] - temp;
		if (n < B.size()) temp -= B[n];
		C.push_back((temp + 10) % 10);//����һ����Ҫ��λ��������ʱtempӦ��
		if (temp < 0)	temp = 1;
		else temp = 0;
	}
	/*	if (C.size() > 1)
		{

			while (C[C.size()-1] == 0)
			{
				C.pop_back();//�ᶯ̬�ı�size
			}
		}*/
	while (C.size() > 0 && C.back() == 0) C.pop_back();
	return C;
}
int main()
{
	string a, b;
	vector<int>A, B;
	cin >> a >> b;
	for (int n = a.size() - 1; n >= 0; n--)
	{
		A.push_back(a[n] - '0');
	}
	for (int n = b.size() - 1; n >= 0; n--)
	{
		B.push_back(b[n] - '0');
	}
	if (cmp(A, B))//A>B
	{
		auto C = sub(A, B);
		for (int n = C.size() - 1; n >= 0; n++)
		{
			cout << C[n];
		}
	}
	else
	{
		auto C = sub(B, A);//B>a
		for (int n = C.size() - 1; n >= 0; n++)
		{
			cout << C[n];
		}
	}

	return 0;
}
