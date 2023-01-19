#include<iostream>
using namespace std;

const int N = 100010;


int main()
{
	int qrr[N], n=0, m=0;
	qrr[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin>> qrr[i];//前缀和的初始化
	}
	for (int i = 1; i <= n; i++)
	{
		qrr[i] = qrr[i - 1] + qrr[i];//前缀和计算部分，注意在这里没有保存初始数组数据
	}
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << qrr[b] - qrr[a - 1]<<endl;//利用元素法理解
	}
	return 0;
}
