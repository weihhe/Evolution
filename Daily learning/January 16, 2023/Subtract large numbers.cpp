#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int>& A, vector<int>& B)//A>=B 返回TRUE FLASE
{
	if (A.size() != B.size()) return A.size() > B.size();//首先判断位数，位数不同且A>B返回 TRUE
	for (int n = A.size() - 1; n >= 0; n--)
	{
		if (A[n] != B[n])
		{
			return A[n] > B[n];//在长度相同时，比较较高位元素的大小
		}
		return true;//当A,B完全一样的时候，同样返回TRUE
	}
}
vector<int> sub(vector<int>& A, vector<int>& B)//保证了A>=B
{
	vector<int>C;
	for (int n = 0, temp = 0; n < A.size(); n++)
	{
		temp = A[n] - temp;
		if (n < B.size()) temp -= B[n];
		C.push_back((temp + 10) % 10);//对于一个需要进位的数，此时temp应该
		if (temp < 0)	temp = 1;
		else temp = 0;
	}
	/*	if (C.size() > 1)
		{

			while (C[C.size()-1] == 0)
			{
				C.pop_back();//会动态改变size
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
